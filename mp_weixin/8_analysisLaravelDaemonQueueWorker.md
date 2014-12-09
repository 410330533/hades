今天我们看下 php Laravel 框架实现的 daemon queue worker 的实现。可以先看下 link 的链接，了解下 daemon queue worker 是什么，怎么用，有个大概的了解，然后我们再详细进到源码里看下，分析下其如何实现。

大体上，deamon queue worker 有下面3种使用方式
```shell
php artisan queue:work connection --daemon
php artisan queue:work connection --daemon --sleep=3
php artisan queue:work connection --daemon --sleep=3 --tries=3

php artisan queue:restart
```

我们看下 queue:work 的一些参数，在代码 Console/WorkCommand.php 中，我们可以看到 getOptions 函数，如下
```php
    protected function getOptions()
    {
        return array(
            array('queue', null, InputOption::VALUE_OPTIONAL, 'The queue to listen on'),

            array('daemon', null, InputOption::VALUE_NONE, 'Run the worker in daemon mode'),

            array('delay', null, InputOption::VALUE_OPTIONAL, 'Amount of time to delay failed jobs', 0),

            array('force', null, InputOption::VALUE_NONE, 'Force the worker to run even in maintenance mode'),

            array('memory', null, InputOption::VALUE_OPTIONAL, 'The memory limit in megabytes', 128),

            array('sleep', null, InputOption::VALUE_OPTIONAL, 'Number of seconds to sleep when no job is available', 3),

            array('tries', null, InputOption::VALUE_OPTIONAL, 'Number of times to attempt a job before logging it failed', 0),
        );
    }
```
每个参数的意思，也说的比较清楚。我们这边再解释下其中几个
- daemon 在 daemon 模式下跑 worker
- memory 内存限制，单位是MB，默认为128
- sleep 当没有 job 需要执行时，sleep的秒数
- tries 失败时的重试次数

WorkCommand 在构造函数中，需要传入一个 worker
```php
    public function __construct(Worker $worker)
    {
        parent::__construct();

        $this->worker = $worker;
    }
```
然后执行 command，会调用 `fire` 函数
```php
    public function fire()
    {
        if ($this->downForMaintenance() && ! $this->option('daemon')) return;

        $queue = $this->option('queue');

        $delay = $this->option('delay');

        // The memory limit is the amount of memory we will allow the script to occupy
        // before killing it and letting a process manager restart it for us, which
        // is to protect us against any memory leaks that will be in the scripts.
        $memory = $this->option('memory');

        $connection = $this->argument('connection');

        $response = $this->runWorker(
            $connection, $queue, $delay, $memory, $this->option('daemon')
        );

        // If a job was fired by the worker, we'll write the output out to the console
        // so that the developer can watch live while the queue runs in the console
        // window, which will also of get logged if stdout is logged out to disk.
        if ( ! is_null($response['job']))
        {
            $this->writeOutput($response['job'], $response['failed']);
        }
    }
```
`fire` 函数中，会 invoke `runWorker` 函数，并传入一些参数，包括 connection, queue, delay, memory, daemon, 然后我们看 `runWorker` 函数
```php
    protected function runWorker($connection, $queue, $delay, $memory, $daemon = false)
    {
        if ($daemon)
        {
            $this->worker->setCache($this->laravel['cache']->driver());

            $this->worker->setDaemonExceptionHandler($this->laravel['exception']);

            return $this->worker->daemon(
                $connection, $queue, $delay, $memory,
                $this->option('sleep'), $this->option('tries')
            );
        }

        return $this->worker->pop(
            $connection, $queue, $delay,
            $this->option('sleep'), $this->option('tries')
        );
    }
```
如果是 daemon，会调用几个设置函数 `setCache`, `setDaemonExceptionHandler`, 然后调用 worker 的 `daemon` 函数。如果不是 daemon，则会调用 worker 的 `pop` 函数。接下来我们看下 worker 的 `daemon` 函数。
```php
    public function daemon($connectionName, $queue = null, $delay = 0, $memory = 128, $sleep = 3, $maxTries = 0)
    {
        $lastRestart = $this->getTimestampOfLastQueueRestart();

        while (true)
        {
            if ($this->daemonShouldRun())
            {
                $this->runNextJobForDaemon(
                    $connectionName, $queue, $delay, $sleep, $maxTries
                );
            }
            else
            {
                $this->sleep($sleep);
            }

            if ($this->memoryExceeded($memory) || $this->queueShouldRestart($lastRestart))
            {
                $this->stop();
            }
        }
    }
```
首先，调用 `getTimestampOfLastQueueRestart` 获取上一次 restart 时的 timestamp，然后就直接 while true。调用 `daemonShouldRun` 判断 daemon 是否该跑，如果是的话，就执行 `runNextJobForDaemon`，并传入参数，这也就是跑 daemon 的主要逻辑了。如果不是，就 sleep(还记得 command 的参数里有这个值吗？)。执行完 job 后，执行一些判断 `memoryExceeded`(这里用到了 memory 参数), `queueShouldRestart`, 来确定是否执行 `stop` 函数来结束程序执行。`sleep` 函数和 `stop` 函数这边就不看了，大家有兴趣自己看下。我们来看下 `runNextJobForDaemon` 函数。
```php
    protected function runNextJobForDaemon($connectionName, $queue, $delay, $sleep, $maxTries)
    {
        try
        {
            $this->pop($connectionName, $queue, $delay, $sleep, $maxTries);
        }
        catch (\Exception $e)
        {
            if ($this->exceptions) $this->exceptions->handleException($e);
        }
    }
```
这里，直接调用了 `pop` 函数，然后 try catch 了一下。还记得 WorkCommand 中的 `runWorker` 函数吗？如果不是 daemon, 在 `runWorker` 中就直接调用了 worker 的 `pop` 函数。是 daemon 的话，经过前面的一些校验逻辑判断等，现在也到了 `pop` 函数。我们来看下 `pop` 函数。
```php
    public function pop($connectionName, $queue = null, $delay = 0, $sleep = 3, $maxTries = 0)
    {
        $connection = $this->manager->connection($connectionName);

        $job = $this->getNextJob($connection, $queue);

        // If we're able to pull a job off of the stack, we will process it and
        // then immediately return back out. If there is no job on the queue
        // we will "sleep" the worker for the specified number of seconds.
        if ( ! is_null($job))
        {
            return $this->process(
                $this->manager->getName($connectionName), $job, $maxTries, $delay
            );
        }

        $this->sleep($sleep);

        return ['job' => null, 'failed' => false];
    }
```
这里就是先 `getNextJob` 来得到 job, 然后 invoke `process` 函数，执行完 job 后，再 `sleep` 一下。看下 `process` 函数。
```php
    public function process($connection, Job $job, $maxTries = 0, $delay = 0)
    {
        if ($maxTries > 0 && $job->attempts() > $maxTries)
        {
            return $this->logFailedJob($connection, $job);
        }

        try
        {
            // First we will fire off the job. Once it is done we will see if it will
            // be auto-deleted after processing and if so we will go ahead and run
            // the delete method on the job. Otherwise we will just keep moving.
            $job->fire();

            if ($job->autoDelete()) $job->delete();

            return ['job' => $job, 'failed' => false];
        }

        catch (\Exception $e)
        {
            // If we catch an exception, we will attempt to release the job back onto
            // the queue so it is not lost. This will let is be retried at a later
            // time by another listener (or the same one). We will do that here.
            if ( ! $job->isDeleted()) $job->release($delay);

            throw $e;
        }
    }
```
先做一些重试次数的判断，然后调用 `$job->fire();` 执行。还有一些扫尾工作，是否 delete。

整个源码就解析到这里。他的执行过程，也就是获取 job，执行，然后考虑 memory, tries等的一些限制，然后 sleep 一下。

# link
- [Daemon Queue Worker](http://laravel.com/docs/4.2/queues#daemon-queue-worker)

今天我们来看下 php Laravel 框架的 `TailCommand` 功能。

`TailCommand` 能做什么？我们来看下代码就知道了，里面包含描述。
```php
class TailCommand extends Command {

    /**
     * The console command name.
     *
     * @var string
     */
    protected $name = 'tail';

    /**
     * The console command description.
     *
     * @var string
     */
    protected $description = "Tail a log file on a remote server";
```
看下这个 `command` 提供了什么可选项
```php
    protected function getOptions()
    {
        return array(
            array('path', null, InputOption::VALUE_OPTIONAL, 'The fully qualified path to the log file.'),

            array('lines', null, InputOption::VALUE_OPTIONAL, 'The number of lines to tail.', 20),
        );
    }
```
2个参数，1个是日志的 `path`，另一个是要 `tail` 的行数。我们再来看下，提供了哪些参数。
```php
    protected function getArguments()
    {
        return array(
            array('connection', InputArgument::OPTIONAL, 'The remote connection name'),
        );
    }
```
`connection` 远端连接的名字。我们看下执行这个 `command` 时，会发生点什么。
```php
    public function fire()
    {
        $path = $this->getPath($this->argument('connection'));

        if ($path)
        {
            $this->tailLogFile($path, $this->argument('connection'));
        }
        else
        {
            $this->error('Could not determine path to log file.');
        }
    }
```
执行 `fire` 函数，调用 `tailLogFile` 函数，我们来看下。
```php
    protected function tailLogFile($path, $connection)
    {
        if (is_null($connection))
        {
            $this->tailLocalLogs($path);
        }
        else
        {
            $this->tailRemoteLogs($path, $connection);
        }
    }
```
这边分成 `local log` 和 `remote log`。先看 `local log`。
```php
    protected function tailLocalLogs($path)
    {
        $output = $this->output;

        $lines = $this->option('lines');

        (new Process('tail -f -n '.$lines.' '.escapeshellarg($path)))->setTimeout(null)->run(function($type, $line) use ($output)
        {
            $output->write($line);
        });
    }
```
实现就是生成 `Process` 实例，然后调用 `run` 函数。再来看下 `remote log`。
```php
    protected function tailRemoteLogs($path, $connection)
    {
        $out = $this->output;

        $lines = $this->option('lines');

        $this->getRemote($connection)->run('tail -f -n '.$lines.' '.escapeshellarg($path), function($line) use ($out)
        {
            $out->write($line);
        });
    }
```
调用 `getRemote` 然后 `run`。看下 `getRemote` 函数。
```php
    protected function getRemote($connection)
    {
        return $this->laravel['remote']->connection($connection);
    }
```
回到 `local log`。所以，我想说的关键点，是在这里。
```php
        (new Process('tail -f -n '.$lines.' '.escapeshellarg($path)))->setTimeout(null)->run(function($type, $line) use ($output)
        {
            $output->write($line);

        });
```
看一下 `process` 的 `run` 函数。
```php
    public function run($callback = null)
    {
        $this->start($callback);

        return $this->wait();
    }
```
看一下 `start` 函数。
```php
    public function start($callback = null)
    {
        if ($this->isRunning()) {
            throw new RuntimeException('Process is already running');
        }
        if ($this->outputDisabled && null !== $callback) {
            throw new LogicException('Output has been disabled, enable it to allow the use of a callback.');
        }

        $this->resetProcessData();
        $this->starttime = $this->lastOutputTime = microtime(true);
        $this->callback = $this->buildCallback($callback);
        $descriptors = $this->getDescriptors();

        $commandline = $this->commandline;

        if (defined('PHP_WINDOWS_VERSION_BUILD') && $this->enhanceWindowsCompatibility) {
            $commandline = 'cmd /V:ON /E:ON /C "('.$commandline.')';
            foreach ($this->processPipes->getFiles() as $offset => $filename) {
                $commandline .= ' '.$offset.'>'.ProcessUtils::escapeArgument($filename);
            }
            $commandline .= '"';

            if (!isset($this->options['bypass_shell'])) {
                $this->options['bypass_shell'] = true;
            }
        }

        $this->process = proc_open($commandline, $descriptors, $this->processPipes->pipes, $this->cwd, $this->env, $this->options);

        if (!is_resource($this->process)) {
            throw new RuntimeException('Unable to launch a new process.');
        }
        $this->status = self::STATUS_STARTED;

        $this->processPipes->unblock();

        if ($this->tty) {
            return;
        }

        $this->processPipes->write(false, $this->input);
        $this->updateStatus(false);
        $this->checkTimeout();
    }
```
主要就是 `proc_open` 函数了。说到底，就是这个函数。好好看下吧。。。

# link
- [proc_open](http://php.net/manual/en/function.proc-open.php)

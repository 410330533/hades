<?php

$message_queue_key = ftok(__FILE__, 'a');
$message_queue = msg_get_queue($message_queue_key, 0666);

$pids = array();
for ($i = 0;  $i < 5; $i++) {
    // 创建子进程
    $pids[$i] = pcntl_fork();
    
    if ($pids[$i]) { // 父进程会得到子进程号，所以这里是父进程执行的逻辑
        echo "No.$i child process was created, the pid is $pids[$i]\r\n";
        pcntl_wait($status); // 等待子进程中断，防止子进程成为僵尸进程
    
    } else if ($pids[$i] == 0) { // 子进程得到的$pid为0, 所以这里是子进程执行的逻辑
        $pid = posix_getpid();
        echo "process.$pid is writing now\r\n";
        
        msg_send($message_queue, 1, "this is process.$pid's data\r\n");
        posix_kill($pid, SIGTERM);
    }
}

do {
    msg_receive($message_queue, 0, $message_type, 1024, $message, true, MSG_IPC_NOWAIT); 
    echo "message = $message \n";

    $mq_st = msg_stat_queue($message_queue);
    if ($mq_st['msg_qnum'] == 0){ // 队列为空，则退出
        break;
    }
} while(true);

echo "end... \n";
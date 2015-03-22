<?php

$forkNum = 3;
$pids = [];

for ($i=0; $i<$forkNum; $i++){
    $pid = pcntl_fork();

    if ($pid == -1) {
        die('could not fork');
    } else if ($pid) {
        // we are the parent
        echo "parent process pid = " . $pid . "\n";
        $pids[] = $pid;
    } else {
        // we are the child
        echo "child process pid = " . $pid . "\n";
        sleep(3 * ($i + 1));
        exit;
    }
} 

foreach ($pids as $pid) {
    echo "Waiting $pid\n";
    pcntl_waitpid($pid, $status);
}

<?php

$local_socket = 'tcp://0.0.0.0:9000';
$serv = stream_socket_server($local_socket, $errno, $errstr)
    or die('create server failed');

while (true) {
    $fp = stream_socket_accept($serv);
    if (pcntl_fork() == 0) {
        $req = fread($fp, 1024);
        $rsp = "echo: " . $req;
        fwrite($fp, $rsp, strlen($rsp));
        fclose($fp);
        exit(0);
    }
}

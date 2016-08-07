<?php

$remote_socket = 'tcp://0.0.0.0:9000';
$timeout = 30;
$fp = stream_socket_client($remote_socket, $errno, $srrstr, $timeout)
    or die('create client failed.');

fwrite($fp, "hello, I am from client\n");
echo fread($fp, 1024);
fclose($fp);

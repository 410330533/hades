<?php

$fd = inotify_init();
// stream_set_blocking($fd, false);
$watch_descriptor = inotify_add_watch($fd, 'test', IN_CLOSE);

while (true) {
    echo "inotify_read...\n";
    $events = inotify_read($fd);
    foreach ($events as $event) {
        print_r($event);
    }
    sleep(1);
}

fclose($fd);

<?php

$dir = $argv[1];
chdir($dir);

// build array according to the files.
$map = [];
foreach (glob('*.jpg') as $filename) {
    $day = '201' . substr($filename, 1, 5);
    if ( ! isset($map[$day]))
        $map[$day] = [];

    $map[$day][] = [
        'old' => $filename,
        'new' => $day . '/' . $filename,
    ];
}

// rename
foreach ($map as $dir => $items) {
    if ( ! file_exists($dir))
        mkdir($dir);

    foreach ($items as $item) {
        rename($item['old'], $item['new']);
        echo sprintf("rename(%s, %s)\n", $item['old'], $item['new']);
    }
}
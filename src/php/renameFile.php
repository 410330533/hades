<?php

$dir = '';
chdir($dir);

function mkdirs($dirs) {
    foreach ($dirs as $dir) {
        if ( ! file_exists($dir))
            mkdir($dir);
    }
}

$newDirs = [];
$map = [];
foreach (glob('*.jpg') as $old) {
    echo "old = $old  \n";
    preg_match('/^P(\d)(\d{2})(\d{2})-(\d{2})(\d{2})(\d{2})([_-]\d+)*\.jpg/', $old, $matches);
    $year = '201' . $matches[1];
    $month = $matches[2];
    $day = $matches[3];

    $key = $year . $month . $day;
    if ( ! isset($newDirs[$key]))
        $newDirs[$key] = true;

    $map[$old] = $key . '/' . $old;
}

mkdirs(array_keys($newDirs));

// rename
foreach ($map as $old => $new) {
    rename($old, $new);
}
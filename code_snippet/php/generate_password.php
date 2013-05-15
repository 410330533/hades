<?php

$small_alpha = 'abcdefghigklmnopqrstuvwxyz';
$big_alpha = strtoupper($small_alpha);
$number = '0123456789';
$all_characters = $small_alpha . $big_alpha . $number;

$n = 10;
$str = '';
for ($i=0; $i<$n; $i++){
    $str .= $all_characters[rand(0, strlen($all_characters) - 1)];
}

echo $str . "\n";

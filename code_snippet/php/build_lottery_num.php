<?php

// 双色球
function shuangseqiu()
{
    $red_balls = range(1, 33);
    $blue_balls = range(1, 16);
    shuffle($red_balls);
    shuffle($blue_balls);
    $red_balls = array_slice($red_balls, 0, 6);
    sort($red_balls);

    foreach ($red_balls as $ball){
        echo str_pad((string) $ball, 2, '0', STR_PAD_LEFT) . " ";
    }
    echo "| ";
    echo str_pad((string) $blue_balls[0], 2, '0', STR_PAD_LEFT);
    echo "\n";
}

shuangseqiu();

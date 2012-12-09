<?php

// @author: mahone
// @weibo: http://weibo.com/mahone3297
// @time: 2011-07-28
// 选择排序

// 交换2个元素位置
function swap(&$x, &$y){
    $tmp = $x;
    $x = $y;
    $y = $tmp;
}

// 选择最小数
function selectMin($arr, $s, $m){
    $pos = $s;
    
    for ($i=$s; $i<$m; $i++){
        if ($arr[$i] < $arr[$pos]){
            $pos = $i;
        }
    }
    
    return $pos;
}

// 选择排序
function selectSort(&$arr){
    $len = count($arr);
    
    for ($i=0; $i<$len; $i++){
        $pos = selectMin($arr, $i, $len);
        if ($i != $pos){
            // 找到的最小数不是第一个数时，交换这两个数
            swap($arr[$i], $arr[$pos]);
        }
    }
}



// 测试
$arr = array(12,36,24,49,85,48,29,38,49,97,46);
selectSort($arr);
echo "end...\n";
var_dump($arr);
<?php
/*
有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
*/
function findKing($n, $m){
    // 初始化
    $num_arr = array();
    for ($i=0; $i<$n; $i++){
        $num_arr[] = true;
    }
    
    $left = $n; // 剩余king
    $count = 1; // 计数
    $i=0; // 位置index
    while ($left > 1){
        $i = $i>=$n ? $i-$n : $i;
        
        if ( ! $num_arr[$i]){
            $i++;
            continue;
        }
        
        if ($count == $m){
            $num_arr[$i] = false;
            $i++;
            $count = 1;
            $left--;
            continue;
        }
        
        $i++;
        $count++;
    }
    
    // 返回位置
    for ($i=0; $i<$n; $i++){
        if ($num_arr[$i]){
            return $i;
        }
    }
}
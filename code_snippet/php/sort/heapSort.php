<?php

// @author: mahone
// @weibo: http://weibo.com/mahone3297
// @time: 2011-07-28
// 堆排序

// 交换2个元素位置
function swap(&$x, &$y){
    $tmp = $x;
    $x = $y;
    $y = $tmp;
}

// 堆调整
function heapAdjust(&$arr, $s, $m){
    $rc = $arr[$s];
    for ($j=2*$s; $j<=$m; $j*=2){
        // 左右子树比较
        if ($j<$m && $arr[$j]<$arr[$j+1]){
            $j++;
        }
        
        // 如果堆条件成立，直接 break
        if ($rc >= $arr[$j]){
            break;
        }
        
        // 交换元素及位置赋值
        $arr[$s] = $arr[$j];
        $s = $j;
    }
    
    $arr[$s] = $rc;
}

// 堆排序
function heapSort(&$arr){
    // 添加头元素
    array_unshift($arr, 0);
    $len = count($arr) - 1;
    
    // 初始化堆
    for ($i=floor($len/2); $i>0; $i--){
        heapAdjust($arr, $i, $len);
    }
        
    for ($i=$len; $i>0; $i--){
        swap($arr[1], $arr[$i]);
        heapAdjust($arr, 1, $i-1);
    }
    
    // 删除头元素
    array_shift($arr);
}



// 测试
$arr = array(12,36,24,85);
heapSort($arr);
echo "end...\n";
var_dump($arr);
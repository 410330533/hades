<?php

// @author: mahone
// @weibo: http://weibo.com/mahone3297
// @time: 2011-07-28

// 冒泡排序
function bubbleSort(&$arr){
	$count = count($arr);
	$sorted = false;// 设置 $sorted 变量，如果已经有序，则不继续比较
	
	for ($i=0; $i<$count-1; $i++){
		if ($sorted){
			return ;
		}
		$sorted = true;
		
		for ($j=0; $j<$count-1-$i; $j++){
			if ($arr[$j] > $arr[$j+1]){
				$tmp = $arr[$j];
				$arr[$j] = $arr[$j+1];
				$arr[$j+1] = $tmp;
				
				$sorted = false;
			}
		}
	}
}
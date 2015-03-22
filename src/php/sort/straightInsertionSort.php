<?php

// @author: mahone
// @weibo: http://weibo.com/mahone3297
// @time: 2011-07-28

// 直接插入排序
function straightInsertionSort(&$arr){
	$count = count($arr);
	
	for ($i=1; $i<$count; $i++){
		$tmp = $arr[$i];
		$j = $i-1;
		
		while ($j>=0 && $tmp<$arr[$j]){
			$arr[$j+1] = $arr[$j];
			$j--;
		}
		
		$arr[$j+1] = $tmp;
	}
}
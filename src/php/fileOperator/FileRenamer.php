<?php
require_once dirname(__FILE__) . '/FileFinder.php';

$root = 'C:\Photos';
$finder = new FileFinder($root, array('jpg'), array(), true);
$finder->run();
$finder->sort('asc');

$i = 766;
foreach ($finder->get_file_path_maper() as $key => $value)
{
	$file_name = 'IMG' . str_pad($i, 4, '0', STR_PAD_LEFT) . 'A.jpg';
	$new_file_path = $root . DIRECTORY_SEPARATOR . $file_name;
	
	echo 'file_path = ' . $new_file_path . "\n";
	rename($key, $new_file_path);
	
	$i++;
}

echo 'count = ' . count($finder->get_file_path_maper());
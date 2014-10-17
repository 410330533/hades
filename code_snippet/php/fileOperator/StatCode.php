<?php

require_once dirname(__FILE__) . '/FileFinder.php';

/**
 * 
 * stat code lines
 * @author Mahone
 * @version 2010-08-21
 * 
 * @example
$finder = new StatCode('E:\php',array('php'),array(),true);
$finder->run();
$finder->sort('desc');

foreach ($finder->get_file_lines_maper() as $key => $value)
{
	echo 'file_path = ' . $key . ', lines = ' . $value . "\n";
}

echo 'count = ' . $finder->get_total_lines();
 * 
 */
class StatCode extends FileFinder
{
	/**
	 * total_lines
	 * @var int
	 */
	protected $_total_lines = 0;
	
	/**
	 * file_lines_maper
	 * @var array
	 */
	protected $_file_lines_maper = array();
	
	/**
	 * get total_lines
	 * @return int
	 */
	public function get_total_lines()
	{
		return $this->_total_lines;
	}
	
	/**
	 * get file_lines_maper
	 * @return array
	 */
	public function get_file_lines_maper()
	{
		return $this->_file_lines_maper;
	}
	
	/**
	 * constructor, invoke parent __construct
	 * @param string $root_directory
	 * @param array $include_file_extension
	 * @param array $exclude_file_extension
	 * @param bool $is_recursion
	 * @return void
	 */
	public function __construct($root_directory, $include_file_extension, $exclude_file_extension, $is_recursion=false)
	{
		parent::__construct($root_directory, $include_file_extension, $exclude_file_extension, $is_recursion);
	}
	
	/**
	 * run!
	 * (non-PHPdoc)
	 * @see FileFinder#run()
	 */
	public function run()
	{
		parent::run();
		
		foreach ($this->_file_path_maper as $key=>$value)
		{
			$this->stat_lines_by_filepath($key);
		}
	}
	
	/**
	 * stat lines by filepath
	 * @param string $file_path
	 * @return void
	 */
	public function stat_lines_by_filepath($file_path)
	{
		// check parameter
		if ( ! is_string($file_path))
		{
			return false;
		}
		
		$handle = fopen($file_path, 'r');
		if ($handle)
		{
			$lines = 0;
			
			while ( ! feof($handle))
			{
				$buffer = fgets($handle);
				$lines++;
			}
			
			fclose($handle);
			$this->_file_lines_maper[$file_path] = $lines;
			$this->_total_lines += $lines;
		}
	}
	
	/**
	 * sort
	 * @param string $direction
	 * @return void
	 */
	public function sort($direction = 'desc')
	{
		if ($direction == 'desc')
		{
			arsort($this->_file_lines_maper, SORT_NUMERIC);
		}
		
		if ($direction == 'asc')
		{
			asort($this->_file_lines_maper, SORT_NUMERIC);
		}
	}
	
}
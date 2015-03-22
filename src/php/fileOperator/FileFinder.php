<?php

/**
 * 
 * @author Mahone
 * @version 2010-08-25
 * 
 * @example
$finder = new FileFinder('E:\php',array(),array(),true);
$finder->run();

foreach ($finder->get_file_path_maper() as $key => $value)
{
	echo 'file_path = ' . $key . ', name = ' . $value . "\n";
}

echo 'count = ' . count($finder->get_file_path_maper());
 *
 */
class FileFinder
{
	/**
	 * root directory
	 * @var string
	 */
	protected $_root_directory = '';
	
	/**
	 * is recursion
	 * @var bool
	 */
	protected $_is_recursion = false;
	
	/**
	 * exclude directory
	 * @var array
	 */
	protected $_exclude_directory = array('.', '..', '.svn');
	
	/**
	 * include file extension
	 * @var array
	 */
	protected $_include_file_extension = array();
	
	/**
	 * exclude file extension
	 * @var array
	 */
	protected $_exclude_file_extension = array();
	
	/**
	 * file path maper
	 * @var array
	 */
	protected $_file_path_maper = array();
	
	/**
	 * get root_directory
	 * @return string
	 */
	public function get_root_directory()
	{
		return $this->_root_directory;
	}
	
	/**
	 * set root_directory
	 * @param string $root_directory
	 * @return void
	 */
	public function set_root_directory($root_directory)
	{
		$this->_root_directory = $root_directory;
	}
	
	/**
	 * get is_recursion
	 * @return bool
	 */
	public function get_is_recursion()
	{
		return $this->_is_recursion;
	}
	
	/**
	 * set is_recursion
	 * @param bool $is_recursion
	 * @return void
	 */
	public function set_is_recursion($is_recursion)
	{
		$this->_is_recursion = $is_recursion;
	}
	
	/**
	 * get exclude_directory
	 * @return array
	 */
	public function get_exclude_directory()
	{
		return $this->_exclude_directory;
	}
	
	/**
	 * set exclude_directory
	 * @param array $exclude_directory
	 * @return void
	 */
	public function set_exclude_directory($exclude_directory)
	{
		// automate add '.', '..', '.svn'
		array_unshift($exclude_directory, '.', '..', '.svn');
		
		$this->_exclude_directory = $exclude_directory;
	}
	
	/**
	 * add exclude_directory
	 * @param string/array $exclude_directory
	 * @return void
	 */
	public function add_exclude_directory($exclude_directory)
	{
		if (is_string($exclude_directory))
		{
			array_push($this->_exclude_directory, $exclude_directory);
		}
		
		if (is_array($exclude_directory))
		{
			$this->_exclude_directory = array_merge($this->_exclude_directory, $exclude_directory);
		}
	}
	
	/**
	 * get include_file_extension
	 * @return array
	 */
	public function get_include_file_extension()
	{
		return $this->_include_file_extension;
	}
	
	/**
	 * set include_file_extension
	 * @param array $include_file_extension
	 * @return void
	 */
	public function set_include_file_extension($include_file_extension)
	{
		$this->_include_file_extension = $include_file_extension;
	}
	
	/**
	 * add include_file_extension
	 * @param string/array $include_file_extension
	 * @return void
	 */
	public function add_include_file_extension($include_file_extension)
	{
		if (is_string($include_file_extension))
		{
			array_push($this->_include_file_extension, $include_file_extension);
		}
		
		if (is_array($include_file_extension))
		{
			$this->_include_file_extension = array_merge($this->_include_file_extension, $include_file_extension);
		}
	}
	
	/**
	 * get exclude_file_extension
	 * @return array
	 */
	public function get_exclude_file_extensin()
	{
		return $this->_exclude_file_extension;
	}
	
	/**
	 * set exclude_file_extension
	 * @param array $exclude_file_extension
	 * @return void
	 */
	public function set_exclude_file_extension($exclude_file_extension)
	{
		$this->_exclude_file_extension = $exclude_file_extension;
	}
	
	/**
	 * add exclude_file_extension
	 * @param string/array $exclude_file_extension
	 * @return void
	 */
	public function add_exclude_file_extension($exclude_file_extension)
	{
		if (is_string($exclude_file_extension))
		{
			array_push($this->_exclude_file_extension, $exclude_file_extension);
		}
		
		if (is_array($exclude_file_extension))
		{
			$this->_exclude_file_extension = array_merge($this->_exclude_file_extension, $exclude_file_extension);
		}
	}
	
	/**
	 * get file_path_maper
	 * @return array
	 */
	public function get_file_path_maper()
	{
		return $this->_file_path_maper;
	}
	
	/**
	 * constructor, init.
	 * @param string $root_directory
	 * @param array $include_file_extension
	 * @param array $exclude_file_extension
	 * @param bool $is_recursion
	 * @return void
	 */
	public function __construct($root_directory, $include_file_extension, $exclude_file_extension, $is_recursion=false)
	{
		$this->_root_directory = rtrim($root_directory, DIRECTORY_SEPARATOR);
		$this->_include_file_extension = $include_file_extension;
		$this->_exclude_file_extension = $exclude_file_extension;
		$this->_is_recursion = $is_recursion;
	}
	
	/**
	 * run!
	 * @return void
	 */
	public function run()
	{
		$this->find($this->_root_directory);
	}
	
	/**
	 * find the files.
	 * @param string $dir_path
	 * @return void, false on failure
	 */
	public function find($dir_path)
	{
		// check parameter
		if ( ! is_string($dir_path))
		{
			return false;
		}
		
		if (is_dir($dir_path))
		{
			if ($dh = opendir($dir_path))
			{
				while (($file = readdir($dh)) !== false)
				{
					$file_path = $dir_path . DIRECTORY_SEPARATOR . $file;
					
					if (is_dir($file_path))
					{
						if ( ! in_array($file, $this->_exclude_directory))
						{
							if ($this->_is_recursion === true)
							{
								$this->find($file_path);
							}
						}
					}
					else
					{
						// exclude file extension, don't add to maper.
						if (in_array($this->get_file_extension_type($file_path), $this->_exclude_file_extension))
						{
							continue;
						}
						
						// if include_file_extension is empty, count all files.
						if (empty($this->_include_file_extension))
						{
							$this->_file_path_maper[$file_path] = $file;
						}
						else
						{
							if (in_array($this->get_file_extension_type($file_path), $this->_include_file_extension))
							{
								$this->_file_path_maper[$file_path] = $file;
							}
						}
					}
				}
			}
		}
	}
	
	/**
	 * get file extension type
	 * @param string $file_path
	 * @return string, false on failure
	 */
	public function get_file_extension_type($file_path)
	{
		// check parameter
		if ( ! is_string($file_path))
		{
			return false;
		}
		
		$tmp = explode('.', $file_path);
		
		if (count($tmp) > 1)
		{
			return end($tmp);
		}
		
		return false;
	}
	
	/**
	 * sort
	 * @param string $direction
	 * @return void
	 */
	public function sort($direction='desc')
	{
		if ($direction == 'desc')
		{
			arsort($this->_file_path_maper, SORT_REGULAR);
		}
		
		if ($direction == 'asc')
		{
			asort($this->_file_path_maper, $ORT_REGULAR);
		}
	}
	
}
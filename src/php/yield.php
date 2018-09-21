<?php

// eg1
// function logger(string $filename)
// {
//     $fp = fopen($filename, 'w+');
//     while ($msg = yield) {
//         fwrite($fp, date('Y-m-d H:i:s') . ' ' . $msg . "\n");
//     }
//     fclose($fp);
// }

// $logger = logger('log');
// $logger->send('hell world...');
// $logger->send('start...');
// $logger->send('end...');



// eg2
// function gen() {
//     $ret = (yield 'yield1');
//     var_dump($ret);
//     $ret = (yield 'yield2');
//     var_dump($ret);
// }

// $gen = gen();
// var_dump($gen->current());    // string(6) "yield1"
// var_dump($gen->send('ret1')); // string(4) "ret1"   (the first var_dump in gen)
//                               // string(6) "yield2" (the var_dump of the ->send() return value)
// var_dump($gen->send('ret2')); // string(4) "ret2"   (again from within gen)
//                               // NULL               (the return value of ->send())



// eg3
function gen() {
    yield 'foo';
    yield 'bar';
}

$gen = gen();
var_dump($gen->send('something'));
// 如之前提到的在send之前, 当$gen迭代器被创建的时候一个renwind()方法已经被隐式调用
// 所以实际上发生的应该类似:
//$gen->rewind();
//var_dump($gen->send('something'));

//这样renwind的执行将会导致第一个yield被执行, 并且忽略了他的返回值.
//真正当我们调用yield的时候, 我们得到的是第二个yield的值! 导致第一个yield的值被忽略.
//string(3) "bar"
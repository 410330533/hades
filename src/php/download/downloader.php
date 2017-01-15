<?php

require "vendor/autoload.php";
use PHPHtmlParser\Dom;


function download_mzitu($id, &$nextId = 0)
{
    $subDir = sprintf('mzitu/%s/', $id);
    $isDownloaded = false;
    if ( ! file_exists($subDir))
        mkdir($subDir, 0777, true);
    else
        $isDownloaded = true;

    $urlPrefix = 'http://www.mzitu.com/';
    $page = 1;
    $url = $urlPrefix . $id . '/' . $page;
    $dom = new Dom;
    $dom->load($url);

    // maxPage
    $maxPage = 1;
    $as = $dom->find('body > div.main > div.content > div.pagenavi > a');
    foreach ($as as $a) {
        $page = (int) $a->find('span')->text();
        if ($page > $maxPage)
            $maxPage = $page;
    }
    echo sprintf("[%s] maxPage = %d\n", __METHOD__, $maxPage);

    // imgArray
    $imgs = $dom->find('body > div.main > div.content > div.main-image > p > a > img');
    $img = $imgs[0];
    $templateImgSrc = $img->getAttribute('src');

    $imgArray = [];
    for ($i=1; $i<$maxPage; $i++) {
        $len = strlen($templateImgSrc);
        $url = sprintf('%s%02d.jpg', substr($templateImgSrc, 0, $len - 6), $i);
        $imgArray[] = [
            'url' => $url,
            'filename' => substr($url, strrpos($url, '/') + 1),
        ];
    }
    // download
    if ( ! $isDownloaded) {
        foreach ($imgArray as $img) {
            echo sprintf("[%s] url = %s, filename = %s\n", __METHOD__, $img['url'], $img['filename']);
            file_put_contents(sprintf('%s%s', $subDir, $img['filename']), file_get_contents($img['url']));
        }
    }

    // nextId
    $url = $urlPrefix . $id . '/' . $maxPage;
    $dom->load($url);
    $as = $dom->find('body > div.main > div.content > div.pagenavi > a');
    foreach ($as as $a) {
        $spanText = (string) $a->find('span')->text();
        if (strpos($spanText, '下一组') !== false) {
            $href = (string) $a->getAttribute('href');
            $rPos = strrpos($href, '/');
            $nextId = (int) substr($href, $rPos + 1);
            return ;
        }
    }
}

$id = '81717';
$loop = 0;
while (true) {
    if ($loop++ >= 3)
        break ;
    download_mzitu($id, $nextId);
    $id = $nextId;
    echo sprintf("[%s] nextId = %d\n", __METHOD__, $nextId);
}

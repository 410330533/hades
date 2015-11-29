```sh
apt-get install shntool
apt-get install cuetools
apt-get install flac
apt-get install lame

sudo add-apt-repository -y ppa:flacon
sudo apt-get update
sudo apt-get install -y flacon

iconv -f gbk -t utf8 x.cue -o x.cue
shntool split -f x.cue -t "%p-%n-%t" x.ape
for file in *.wav; do lame -b 192 "`echo $file | sed "s/'/\\\'/g" | sed 's/ /\\ /g';`" ; done
cuetag x.cue *.mp3
```

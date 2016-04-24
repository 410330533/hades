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
for file in *.wav; do lame -b 320 "$file"; done

shntool conv -i ape -o "cust ext=mp3 lame -b 320 - %f" *.ape

cuetag x.cue *.mp3
```

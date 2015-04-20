# find
```shell
find ~/src -time=mtime -3 -exec ls -l {} \;
find . -name "*.php" -exec dos2unix {} \;
-path pathname -prune: 避开指定子目录pathname查找。
-path expression -prune:避开表达中指定的一组pathname查找。
find . -path "./DontSearchPath" -prune -o -name "datafile*" -print
find . \( -path "./DontSearchPath" -o -path "./DoSearchPath" \) -prune -o -name "datafile*" -print
find . -name "*.php" -exec php -l {} \; | grep -v 'No syntax errors'
find ./ -perm /+x -type f # 搜索当前目录下所有的可执行文件
```

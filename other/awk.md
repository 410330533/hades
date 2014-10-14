# awk
```shell
echo 'one two three four' | awk '{print $1}'
echo 'one two three four' | awk '{print $1, $3}'
echo 'one,two,three,four' | awk -F, '{print $1, $3}'
echo 'one two three four' | awk '{print $(NF-1)}'
echo -e 'one 1\ntwo 2\n three 3' | awk '{sum+=$2} END {print sum}'
```

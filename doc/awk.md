# awk
```shell
echo 'one two three four' | awk '{print $1}'
echo 'one two three four' | awk '{print $1, $3}'
echo 'one,two,three,four' | awk -F, '{print $1, $3}'
echo 'one two three four' | awk '{print $(NF-1)}'
grep 'count' sync_tbSalesOrder_create | awk 'BEGIN {sum=0}{sum+=$3} END {print sum}'
```

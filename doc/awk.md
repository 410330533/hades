# awk
```shell
echo 'one two three four' | awk '{print $1}'
echo 'one two three four' | awk '{print $1, $3}'
echo 'one,two,three,four' | awk -F, '{print $1, $3}'
echo 'one two three four' | awk '{print $(NF-1)}'
grep 'count' sync_tbSalesOrder_create | awk 'BEGIN {sum=0}{sum+=$3} END {print sum}'
grep 'elapse' 0.log | awk  'BEGIN {sum=0;i=0}{sum+=$6;i++} END {print sum/i}'

awk -F ':' '{print NR ") " $1}' demo.txt
awk -F ':' '{ print toupper($1) }' demo.txt
awk -F ':' '/usr/ {print $1}' demo.txt
awk -F ':' 'NR % 2 == 1 {print $1}' demo.txt
awk -F ':' 'NR >3 {print $1}' demo.txt
awk -F ':' '$1 == "root" {print $1}' demo.txt
awk -F ':' '$1 == "root" || $1 == "bin" {print $1}' demo.txt
awk -F ':' '{if ($1 > "m") print $1}' demo.txt
awk -F ':' '{if ($1 > "m") print $1; else print "---"}' demo.txt
```

# link
* http://awk.readthedocs.io/en/latest/index.html

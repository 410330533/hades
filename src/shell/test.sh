#!/bin/bash

# months=( 0 31 28 31 30 31 30 31 31 30 31 30 31 )
# weekday=( Sunday Monday Tuesday Wednesday Thursday Friday Saturday )
for i in 1 2 3; do
    echo for test i=$i
done

if [ 1 = 1 ]; then
    echo 'if test'
else
    echo 'if test else'
fi

sum=0;
for (( i=1; i<=100; i++ )); do
    sum=$(($sum+$i));
done
echo "the result = 1-100 is $sum";

choice=2
case $choice in
    1) echo 'case test home'
        ;;
    2) echo 'case test office'
        ;;
    3) echo 'case test other'
        ;;
    *) echo 'case test default'
esac

len=3
i=0
while [ $i -lt $len ]; do
    i=`expr $i + 1`
    echo while test i=$i
done

sayHello(){
    echo 'sayHello function...'
}

sayHello

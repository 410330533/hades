#!/bin/bash

path=$1

echo '=============================='
echo time `date`

cd $path && git pull && make dirhtml

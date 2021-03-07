#!/bin/bash
a=$1
b=$2
if [ $a -eq $b ]
then
echo "denyu "
elif [ $a -le $b ]
then
echo "xiaoyu"
else
echo "dayu"
fi

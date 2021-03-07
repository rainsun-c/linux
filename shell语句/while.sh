#!/bin/bash
NUM=0
i=0
while [ $i -le 4 ]
do
let NUM+=$i
((i++))
done
echo "total:$NUM"

#!/bin/bash
#frist 
NUM=0
read -p "enter: " x
for((i=1;i<x;i++))
do
((NUM+=i))
done
echo "$NUM hhhh"

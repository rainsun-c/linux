#!/bin/bash
read -p "enter num:" x
if [ $x -le 5 ]
then
echo "$x xiao yu 5"
elif [ $x -gt 5 ]
then
echo "$x da yu 5"
fi

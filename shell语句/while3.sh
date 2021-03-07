#!/bin/bash

while true
read -p "please:" x
     do
	if ((x<5))
	  then
	     echo "ok"
	  break
	fi
echo "no" 
done	

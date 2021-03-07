#!/bin/sh
 
SYSTEM=`uname -s` #获取操作系统类型，我本地是linux
if [[ $SYSTEM = "Linux" ]] ; then #如果是linux的话打印linux字符串,字符串的判断需要[[  ]]不然有警告
echo "Linux"
elif [[ $SYSTEM = "FreeBSD" ]] ; then #条件前后一定要有空格
echo "FreeBSD"
elif [[ $SYSTEM = "Solaris" ]] ; then
echo "Solaris" #字符串的赋值一定不能有空格
else
echo "What?"
fi
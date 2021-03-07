!/bin/bash

read -p "enter;" x
case x in
[1])
echo "$x+1"
;;
[2])
echo "good"
;;
*)
echo "everything"
esac

#!/bin/bash

echo -n "Please input score:"
read S
if [ $S -lt 0 -o $S -gt 100 ]
then
	echo "not in [0-100]"
	exit
fi

G=`expr $S / 10`
case $G in
	10|9)
		echo "$S A(优秀)"
		;;
	8)
		echo "$S B(良好)"
		;;
	7)
		echo "$S C(良好)"
		;;
	6)
		echo "$S D(及格)"
		;;
	*)
		echo "$S E(不及格)"
		#;;
esac

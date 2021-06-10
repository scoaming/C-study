#!/bin/bash

I=0
while [ $I -lt 5 ] 
do
	I=`expr $I + 1`
	echo -n "input score:"
	read S

	case `expr $S / 10` in
	10|9)
		echo "A"
		;;
	6|7|8)
		echo "B"
		;;
	*)
		echo "C"
		;;
	esac
	echo "$I"
done

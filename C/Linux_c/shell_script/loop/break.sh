#!/bin/bash

I=1

while [ $I -lt 5 ]
do
	J=1
	while [ $J -lt 5 ]
	do
		if [ $J -gt 3 ]
		then
			break 2
		fi
		echo "$I-$J"
		J=`expr $J + 1`
	done
	I=`expr $I + 1`
done

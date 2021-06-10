#!/bin/bash

if [ $# -ne 5 ]
then
	echo "argument 5"
	exit
fi

for I
do
	if [ `expr $I % 2` -eq 1 ]
	then
		echo "$I"
	else
		continue
		#break
	fi
done

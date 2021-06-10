#!/bin/bash
#if ! [ $# = 1 ]
#then
#	echo "please input one filename!"
#	exit
#fi
echo "please input filename/n"
read FILE

if [  -c $FILE ]
then
	cp $FILE /dev
	echo "$FILE copied /deb"
else
	echo "not Charactor device file"
fi

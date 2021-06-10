#!/bin/bash

if [ $# -ne 1 ]
then
	echo "usage:$0 filename"
	exit
fi
if ! [ -e $1 ]
then
	echo "$1 not exist!"
	exit
fi
if [ -d $1 ]
then
	echo "$1 is a directory"
elif [ -L $1 ]
then
	echo "L"
elif [ -f $1 ]
then
	echo "-"
elif [ -b $1 ]
then
	echo "b"
elif [ -c $1 ]
then
	echo "c"
elif [ -S $1 ]
then
	echo "s"
else
	echo "p"
fi

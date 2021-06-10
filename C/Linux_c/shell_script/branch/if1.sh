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
fi

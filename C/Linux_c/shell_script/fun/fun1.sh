#!/bin/bash

grep_user()
{
	R=`grep "$1" /etc/passwd | wc -l`
	echo $R
	return $R	
}

echo -n "input username:"
read USER
grep_user $USER
RET="$?"
if [ $RET -eq 1 ]
then
	echo "$USER exist"
else
	echo "$USER not exist"
fi

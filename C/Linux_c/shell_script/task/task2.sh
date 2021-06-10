#!/bin/bash

grep_user()
{
	R=`grep "$1" /etc/passwd | wc -l`
	echo $R
}

echo -n "input username:"
read USER
RET=`grep_user $USER`
echo "----return $RET----"
if [ $RET -eq 1 ]
then
	echo "$USER exist"
else
	echo "$USER not exist"
	sudo adduser $USER
	echo "$USER is now created"
fi

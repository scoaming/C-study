#!/bin/bash

if [ $# = 2 ]
then
	loop=$2
else
	loop=5
fi
i=1
while [ $i -lt $loop ]
do
	>$1$i
	i=`expr $i + 1`
done

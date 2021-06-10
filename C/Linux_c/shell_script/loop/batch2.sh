#!/bin/bash

i=1

echo -n "input number of creat or delete:"
read S

while [ $i -lt $S ]
do
	rm blank$i
	i=`expr $i + 1`
done

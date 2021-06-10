#!/bin/bash

SUM=0
for I in `seq 1 100`
do
SUM=`expr $SUM + $I`
done
echo "$SUM"

for ((I = 1; I <=10; I++))
do
echo "I = $I"
done

for ((;;))
do
echo "for"
done

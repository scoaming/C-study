#!/bin/bash

A=99
B=78
test $A -eq $B
echo $?

test $A -lt $B
echo $?

test $A -gt $B
echo $?

#!/bin/bash

A="Hello"
B="Hello"
test $A = $B
echo $?

pwd
echo $?

ls inexistence
echo $?

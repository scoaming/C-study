#!/bin/bash


test -d /home/farsight/c/Linux_c/shell_scrip/expr.sh
echo $?

test -f expr.sh
echo $?

test -e inexistence
echo $?

test -r $HOME/c/Linux_c/shell_script/read.sh
echo $?
test -r read.sh
echo $?

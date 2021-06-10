#!/bin/bash

echo -n "Please choose (yes|no)?"
read R
case $R in
	yes | YES | Y | y | Yes)
		echo "yes"
		;;
	no|NO|n|N|No)
		echo "no"
		;;
	*)
		echo "wrong"
		#;;
esac

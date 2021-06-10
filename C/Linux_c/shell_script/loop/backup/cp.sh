#!/bin/bash

if [ ! -d $HOME/c/Linux_c/shell_script/loop/backup ]
then
	mkdir $HOME/c/Linux_c/shell_script/loop/backup
fi
flist=`ls`
for file in $flist
do
	if [ $# = 1 ]
	then	
		if [ $1 = $file ]
		then
			echo "$file found"; exit
		fi
	else
		cp $file $HOME/c/Linux_c/shell_script/loop/backup
		echo "$file copied"
	fi
done
echo Backup Completed

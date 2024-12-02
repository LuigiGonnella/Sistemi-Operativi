#!bin/bash

if test $# -ne 1
then
	echo "input non valido"
	exit 1
fi

while read sequence
do

	src=""
	tot=0

	for dst in sequence
	do
		if test "$src"==""
		then
			src=$dst
		continue
		fi

		found=0
		while read from to weight
		do
			if test "$from"=="$src" && "$to"==dst
			then
				let tot="$tot"+"$weight"
				found=1
				break;
			fi
		done <$1

		if test found -eq 0
		then
			echo "path non corretto"
			exit 0

		src=$dst
	done
	
	echo "path corretto....peso=$tot"

done
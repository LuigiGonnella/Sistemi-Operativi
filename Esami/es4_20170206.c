#!bin/bash

if test $# -ne 2
then
  echo "I parametri devono essere 2"
  exit -1
fi

if test ! -f $1 -o ! -f $2
then
  echo "I parametri devono file"
  exit -1
fi


while read str
do
  while read num
  do
    flag=0
    while read str2
    do	
      while read num2
      do
	if test $num -eq $num2
	then
	  flag=1
	fi



      done < str2

    done < $2
    if test $flag -eq 0
    then
      echo "$num\n"
    fi
  done < str


done < $1




while read str
do
  while read num
  do
    flag=0
    while read str2
    do	
      while read num2
      do
	if test $num -eq $num2
	then
	  flag=1
	fi



      done < str2

    done < $1
    if test $flag -eq 0
    then
      echo "$num\n"
    fi
  done < str


done < $2
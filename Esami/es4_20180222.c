#!bin/bash

#run es4.sh filename n1 n2 n3

if test $# -ne 4
then
  echo "Error, incorrect number of inputs"
  exit(-1)
fi

if test $2 -le 0 || $3 -le 0 || $4 -le 0
then
  echo "Error, input numbers must be positive"
  exit(-1)
fi

if test n1 -ge n2
then
  echo "Error, must be n1<n2"
  exit(-1)
fi

while read path
do
  if test !-f $path
  then
   echo "Invalid path"
   exit(-1)
  fi

  nbytes=$(wc -c $path)
  if test nbytes -lt $2
  then
   rm $path
  fi

  if test nbytes -ge $2 -a nbytes -le $3
  then
   continue
  fi

  if test nbytes -gt $3
  then
   i=1
   while read sequence
   do
     let "i--"
     if test i -eq 0
     then
      echo $sequence >> "$path.compresso"
      i=$4
     fi
     

   done < $path
  fi

done < $1 
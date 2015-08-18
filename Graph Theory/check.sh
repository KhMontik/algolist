#! /bin/bash
for i in *
do 
  if [ -d "$i" ] 
  then
    cd "$i"
    ../.././change
    for j in *.cpp
    do
      ../.././add $j
    done
    cd ..
  fi
done

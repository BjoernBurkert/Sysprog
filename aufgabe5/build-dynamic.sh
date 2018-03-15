#!/bin/sh 
for s in liste.c fachnote.c; do 
    compile_command="gcc -W -Wall -ansi -pedantic -c -fpic $s"
    echo $compile_command
    eval $compile_command
    if [ $? -ne 0 ] ; then
      echo build failed
      exit 1
    fi
done
link_command="gcc -shared fachnote.o liste.o -o libaufgabe5.so"
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then
   echo build failed
   exit 1 
fi 
link_command="gcc notenspiegel.o -L. -laufgabe5 -o notenspiegel"
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then
   echo build failed
   exit 1 
fi 
echo build successful  
 

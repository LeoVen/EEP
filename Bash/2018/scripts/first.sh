#!/bin/bash

# ---------- ---------- ---------- ---------- ---------- #
# ---------- ------- Unique Characters ------ ---------- #
# ---------- ---------- ---------- ---------- ---------- #

echo "Hello"; echo "World!"

var=hello
echo "The word $var has ${#var} characters"

echo $(( 2#111 )) 

colors="red black blue"

for col in $colors
do
    echo $col
done

for col in "$colors"
do
    echo $col
done

echo '$colors'

let "var1=((var2=20, 10/2))"

echo $var1
echo $var2

var="Hello World!"
echo ${var,}
echo ${var,,}

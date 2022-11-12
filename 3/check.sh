#!/bin/bash

#if [[ ! -f ./app.exe]]
 #   echo "make build"

dir="./matrix_data/standart/"

matrixFlag='1'
fileFlag='2'
list=$(find $dir -type f -name "*_m.txt")
    

for matrix in $list; do
    number=$(echo "$matrix" | grep -o "[0-9]*")
    vector=$(find ./matrix_data/standart/ -type f -name ""$number"_v.txt")

    args="file $matrix $vector"
    #valgrind
    ./app.exe "$args"
    rc=$?

    if [ $rc -eq 0 ]; then
        echo -e "\033[0m Test $number: \033[32m PASSED \033[0m"
    else
        echo -e "\033[0m Test $number: \033[31m FAILED \033[0m"
    fi
done

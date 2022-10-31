#!/bin/bash

#if [[ ! -f ./app.exe]]
 #   echo "make build"

dir="./matrix_data/standart/"

matrixFlag='1'
fileFlag='2'
list=$(find $dir -type f -name "*_m.txt")
    

for file_m in $list; do
    number=$(echo "$file_m" | grep -o "[0-9]*")
    file_v=$(find ./matrix_data/standart/ -type f -name ""$number"_v.txt")

    args="file $file_m $file_v"
    echo $args
    #valgrind
    ./app.exe "$args"
    rc=$?

    if [ $rc -eq 0 ]; then
        echo -e "\033[0m Test $number: \033[32m PASSED \033[0m"
    else
        echo -e "\033[0m Test $number: \033[31m FAILED \033[0m"
    fi
done

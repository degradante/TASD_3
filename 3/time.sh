#!/bin/bash

dir="./measuring_data"
    
sparses_procent="1 5 10 20 30 50 100"
sizes="10 50 100 300 500 1000"

i=1
len=42
for size in $sizes; do
    for procent in $sparses_procent; do
        args="random $size $procent"
        ./app.exe $args > $dir/data_"$size"_"$procent"
        
        rc=$?
        if [ $rc -eq 0 ]; then
            let "proc=$i * 100 / $len"
            echo -n -e " $proc%\r"
            ((i++))
            #echo -e "\033[0m Test "$size"_"$procent" : \033[32m PASSED \033[0m"
        else
            echo -e "\033[0m Test "$size"_"$procent" : \033[31m FAILED \033[0m"
            break
        fi
    done
done

#!/bin/bash

dir="./matrix_data/standart/"

list=$(find $dir -type f -name "*.txt")
    
for i in $list; do
    dos2unix $i
done

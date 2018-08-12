#!/bin/bash
while [[ 1 ]]; do
    b=0
    read a
    for(( j = 2; j*j <= a; j++ )); do
        if [[ a%j -eq 0 ]]; then
            b=1 
            echo NO
            break
        fi    
    done
    if [[ b -eq 0 ]]; then
        echo YES
    fi
done

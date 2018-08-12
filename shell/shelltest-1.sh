#!/bin/bash
is_prime() {
    for (( j=2; j<$1; j++ )); do 
        if [[ $1%j -eq 0 ]]; then
            return 0
        fi
    done
    return 1
}
for (( i=2; i<10000; i++ )); do
    is_prime $i
    if [[ $? -eq 1 ]]; then
        echo $i
    fi
done

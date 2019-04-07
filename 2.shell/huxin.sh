#!/bin/bash
for i in `seq 11 20`; do
    scp str.sh pi$i:/home/mason/
done

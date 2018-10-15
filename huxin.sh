#!/bin/bash
for i in `seq 11 20`; do
    scp ~/.ssh/id_rsa.pub pi$i:~/authorized_keys
    ssh pi$i mkdir .ssh
    ssh pi$i mv authorized_keys .ssh
done

#!/bin/bash
if [-d /oldboy] || mkdir /oldboy
cd oldboy
echo `pwd` && \
for i in {1..10}; do
#    filename=$(uuidgen|tr '0-9' 'a-z' |cut -c 1-10 )
#  touch ${filename}_oldboy.html
done

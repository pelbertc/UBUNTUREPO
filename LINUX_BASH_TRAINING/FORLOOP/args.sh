#!/bin/bash

#go through all arguments and print them all

COUNT=1

for ARG in "$@"
#this will print each argument in separate strings or line	   
#for ARG in "$*" this will print all arguments as one string
do
    echo "$COUNT. argument: $ARG"
    let COUNT++
done

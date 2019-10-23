#!/bin/bash

#go through all arguments and print them all

COUNT=1

for ARG in "$@"
do
  echo "$COUNT. argument: $ARG"
  let COUNT++
done

#!/bin/bash

#backup prod directory all .pdf /prod
#Script takes one argument:
#Destination path - which needs to ends with /backup e.g.
#/home/pate/LINUX_BASH_TRAINING/IFSTATEMENT/wildcards

PROD=/home/pate/LINUX_BASH_TRAINING/IFSTATEMENT/wildcards/prod

#arguments check
if [ $# -ne 1 ]; then
  echo "Only one argument is needed, run $0 destination-path"
  exit 1
fi

#destination path check
DESTINATION=$1
if [[ $DESTINATION != */backup ]]; then
  echo Wrong destination path, destination path must ends with /backup
  exit 2
fi

#create destination folder 
DATE=$(date +%Y-%m-%d_%H_%M_%S)
mkdir -p $DESTINATION/$DATE

#copy from prod to destination
cp $PROD/*pdf $DESTINATION/$DATE

#test exit status of copy command
if [ $? -eq 0 ]; then
	echo backup OK
else
	echo backup failed
fi

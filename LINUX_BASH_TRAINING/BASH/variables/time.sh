#!/bin/bash

#start time measurement from here
START=$(date +%s)
CURRENT_DIRECTORY=$(pwd)
cp read.sh /home/pate #sleep 2 seconds
END=$(date +%s)

#end time measurement
DIFFERENCE=$(( END - START))

echo 
echo Time elapsed: $DIFFERENCE seconds.

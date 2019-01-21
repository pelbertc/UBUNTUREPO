#!/bin/bash
NUMBER=7

#do the NUMBER + 7

#do ---let---
let RESULT=NUMBER+7
echo Result from let: $RESULT
let RESULT1=NUMBER-2
echo Result from let: $RESULT1

#do ---(())---
RESULT=$(( NUMBER + 5 ))
echo "Result from (()): $RESULT"

#do ---[]---
RESULT=$[NUMBER + 5 ]
echo Result from []: $RESULT

#do ---expr---
RESULT=$(expr $NUMBER + 5)
echo Result from expr: $RESULT

#do ---bc--- NUMBER * 1.9
RESULT=`echo "$NUMBER * 1.9" | bc`
echo Result from bc: $RESULT



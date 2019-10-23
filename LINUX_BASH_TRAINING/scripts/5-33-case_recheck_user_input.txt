#!/bin/bash

# read data from users and make them option to recheck if provided data are correct

echo -n "Enter your name: "
read NAME
echo -n "Enter your age: "
read AGE
echo -n "Enter your department: "
read DEP

echo "You have entered following: "
echo "Name: 		$NAME"
echo "AGE: 		$AGE"
echo "Department: 	$DEP"

CHECK=0
while [ $CHECK -eq 0 ]
do

echo -n "Is that correct? [Y/n] "
read ANSWER

case "$ANSWER" in
  * ) 
	exit 1
	;;

  "Y"|"y" )
	echo "Name:             $NAME" >> empl.txt
	echo "AGE:              $AGE" >> empl.txt
	echo "Department:       $DEP" >> empl.txt
	echo "=================================" >>empl.txt
	echo "Your data were saved into employee file"
	CHECK=1
	;;

  N|n )
	echo "Nothing was saved, run the script again if you want to add date to employee file"
	CHECK=1
	;;
  * )
	echo "Wrong answer provided"
	;;
esac
done
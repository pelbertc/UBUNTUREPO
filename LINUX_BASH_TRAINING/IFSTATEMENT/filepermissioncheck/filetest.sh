#READ:   YES
#WRITE:  NO
#EXECUTE:NO

#argument check
if [ $# -ne 1 ]; then
   echo "Provide exactly one argument"
   exit 1
fi

#variable assignment
   FILE=$1

#check if the file exists
   if [ -f $FILE ]; then

#default variables
    VAR_READ="NO"
    VAR_WRITE="NO"
    VAR_EXE="NO"

#check if the files is readable
   if [ -r $FILE ]; then
     VAR_READ="YES"
   fi

#check if the files is writeable
   if [ -w $FILE ]; then
     VAR_WRITE="YES"
   fi
#check if the files is executable
   if [ -x $FILE ]; then
     VAR_EXE="YES"
   fi

#write summary to user
   echo ====FILE: $FILE====
   echo "READ:       $VAR_READ"
   echo "WRITE:      $VAR_WRITE"
   echo "EXECUTABLE: $VAR_EXE"

       else
	     if [ -d $FILE ]; then
	       echo $FILE is a directory
       else

        echo $FILE does not exists
     fi
   fi  

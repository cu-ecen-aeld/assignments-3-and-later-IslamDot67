#!/bin/sh
#echo "Finder App" 

filesdir=$1
searchstr=$2

#echo "Input Parameters count: $#"
#echo "  Files Directory: ${filesdir}" 
#echo "  Search String: ${searchstr}"

if [ -z $filesdir ] 
then
  #echo filesdir argument is missing.
  exit 1
elif [ -z $searchstr ]
then
  #echo searchstr argument is missing
  exit 1
elif [ ! -d $filesdir ]
then	
  #echo $filesdir is not a directory.
  exit 1
else
  #echo Executing 
  number_files=$( find $filesdir -type f | wc -l )
  matches=$( grep -R $searchstr $filesdir | wc -l )
  echo "The number of files are ${number_files} and the number of matching lines are ${matches}"   
  exit 0
fi      

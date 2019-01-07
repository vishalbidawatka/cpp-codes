#!/bin/bash

args=("$@");
cd ${args[0]}
 echo ${args[0]}
 echo ${args[1]}
file=(`ls`);

 for t in "${file[@]}"
 do
  extension=$(echo $t | grep -o '\..*' | cut -d '.' -f 2)
  ch="n"
	if [ ${args[1]} = "all" ]
	then
	 ch="y"
	fi
   
   for z in "${args[@]}"
   do
    if [ "$extension" = "$z" ];
    then
     ch="y"
     echo $extension
     break;
    fi
   done
   if [ "$ch" = "y" ];
    then
      if [ ! -d $extension ];
       then
	       mkdir  $extension;
  
       fi
      mv $t $extension
	

   fi


 done

 exit 0

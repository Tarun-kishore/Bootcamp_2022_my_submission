#! /bin/sh

`mkdir root`
for (( i = 1; i <= 5; i++ )); do
    `mkdir root/dir$i/`
    for (( j = 1; j <= 4; j++ )); do
       `touch root/dir$i/file$j` 

       for (( k = 1; k <= j; k++ )); do
          `echo "$j" >> root/dir$i/file$j` 
       done

    done

    
done

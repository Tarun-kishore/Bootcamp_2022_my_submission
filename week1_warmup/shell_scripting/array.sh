#! /bin/sh

arr[0]="man"
arr[1]="bear"
arr[2]="pig"
arr[3]="dog"
arr[4]="cat"
arr[5]="sheep"

for (( i = 0; i < 6; i++ )); do
    echo ${arr[$i]}
done

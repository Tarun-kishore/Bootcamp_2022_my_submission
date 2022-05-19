#! /bin/sh
SUM=0


for (( i = $1; i > 0 ; i = i/10 )); do
    SUM=$(( $SUM + $i%10))
done

echo $SUM

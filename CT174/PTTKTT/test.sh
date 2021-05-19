echo $1 > dayso.inp
DIFF=$(($3-$2+1))
RANDOM=$S
for i in `seq $1`
do
	R=$(($(($RANDOM%DIFF))+$2))
	echo $R >> dayso.inp
done


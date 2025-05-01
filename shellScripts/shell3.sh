echo Enter 3 numbers:
read a b c
if [ $a -ge $b ] && [ $a -ge $c ]
then
	echo $a is maxmum
elif [ $b -ge $c ]
then
	echo $b is maximum
else
	echo $c is maximum
fi

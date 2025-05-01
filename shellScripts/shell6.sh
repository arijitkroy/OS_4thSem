echo Enter number to find factorial: 
read n
let f=1
while [ $n -ne 0 ]
do
	f=`expr $f \* $n`
	n=`expr $n - 1`
done
echo Factorial is $f

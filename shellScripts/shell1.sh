echo -e "Enter number 'a': \c"
read a
echo -e "Enter number 'b': \c"
read b
echo -e "Operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nEnter choice: \c"
read ch
case $ch in
	1) echo $a + $b = `expr $a + $b`;;
	2) echo $a - $b = `expr $a - $b`;;
	3) echo $a \* $b = `expr $a \* $b`;;
	4) echo $a / $b = `expr $a / $b`;;
	5) exit;;
esac

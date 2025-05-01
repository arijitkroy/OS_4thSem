echo -e "Menu:\n1. LS\n2. PWD\n3. CAL\n4. EXIT\nEnter choice: \c"
read ch
case $ch in
	1) ls;;
	2) pwd;;
	3) cal;;
	4) exit;;
	*) echo Invalid option
esac

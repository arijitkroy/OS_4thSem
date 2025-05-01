echo Number of lines:
read n
for (( i=1; i<=n; i++ )) do
	for (( j=1; j<=i; j++ )) do
		echo -e "*\c"
	done
	echo
done

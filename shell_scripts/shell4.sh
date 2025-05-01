echo Enter 3 numbers:\c
read a b c
if [[ ( $a -gt $b && $a -lt $c ) || ( $a -gt $c && $a -lt $b ) ]]; then
    echo "$a is second maximum"
elif [[ ( $b -gt $a && $b -lt $c ) || ( $b -gt $c && $b -lt $a ) ]]; then
    echo "$b is second maximum"
else
    echo "$c is second maximum"
fi

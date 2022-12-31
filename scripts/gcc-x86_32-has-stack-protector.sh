#!/bin/sh

echo "int foo(void) { char X[200]; return 3; }" | $* -S -x c -c -Ofast -fstack-protector - -o - 2> /dev/null | grep -q "%gs"
if [ "$?" -eq "0" ] ; then
	echo y
else
	echo n
fi

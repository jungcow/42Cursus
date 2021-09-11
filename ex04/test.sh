#! /bin/zsh

if [ $# -ne 2 ]
then
	USAGE="Usage: ./test.sh [str_to_find] [str_to_replace]"
	echo $USAGE | grep --colour=always "Usage"
	exit 1
fi

make && make clean;

./replace test $1 $2

echo "\n"
cat test | grep --colour=always $1;
echo "\n=====================================================================\n"
cat test.replace | grep --colour=always $2;

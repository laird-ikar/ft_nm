#!bash

make

ft="$(ft_nm -a --no-sort $1 $2 2>&1)"
og="$(nm -a --no-sort $1 $2 2>&1)"

if [ "$ft" == "$og" ]
then
	printf "OK"
else
	diff <(echo "$ft") <(echo "$og")
fi

declare -a ARGS

if [[ "$1" == "re" ]]
then
	make re
elif [[ "$2" == "re" ]]
then
	make re
fi

for i in {0..99}
do
	if (($i % 8 == 0))
	then
		ARGS[$i]=$i
	else
		ARGS[$i]=-$i
	fi
done

echo "${ARGS[@]}"

if [[ $1 == *"-"* ]]
then
	options=$1
elif [[ $2 == *"-"* ]]
then
	options=$2
else
	options=""
fi
./push_swap ${ARGS[@]} | ./checker $options ${ARGS[@]}

declare -a ARGS

for i in {0..99}
do
	if (($i % 2 == 0))
	then
		ARGS[$i]=$i
	else
		ARGS[$i]=-$i
	fi
done

echo "${ARGS[@]}"

./push_swap ${ARGS[@]} | ./checker -n ${ARGS[@]}

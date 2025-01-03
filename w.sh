#!/bin/bash

info() {
	echo -e "\033[36m$1\033[0m"
}
warning() {
	echo -e "\033[31m$1\033[0m"
}
success() {
	echo -e "\033[32m$1\033[0m"
}

watch() {
	STATE_A=""
	while [[ true ]]
	do
		STATE_B=$(get_state)
		if [[ $STATE_A != $STATE_B ]]; then
			STATE_A=$STATE_B
			clear
			info "HEY BRO 👋 $(date)"
			./sync.sh

			NORM_ERROR=$(sed -e '/.*: OK!/d' <(norminette))
			if [[ $NORM_ERROR == "" ]] ; then
				success "\nNORMINETTE OK"
			else
				warning "\nNORMINETTE ERROR"
				echo "$NORM_ERROR"
			fi

			echo ""
			PROG="./push_swap"
			PROG_BONUS="./checker"
			#ARGS="2 1 6 3"
			#ARGS="2 1 3 6 5 8"
			#ARGS="3 4 0 2 1 5"
			#ARGS="2 1 3 6 5 8"

			ARGS="2 1 3 6 2147483647 5 2147483645 8 2147483248"
			ARGS="2 1 3 6 214748361 sa 5 214748364 8 214748323"
			#ARGS="22 1 3 65 5 8 20 74 35 54"
			#ARGS="5 11 10 20 14 3 19 16 8 13 9 7 17 4 18 12 1 6 2 15"
			rm -f "$PROG"
			rm -f "$PROG_BONUS"
			make
			make bonus
			if [ ! -f "$PROG" ]; then
				warning "COMPILATION FAILED"
			else
				success "COMPILATION OK, RUN TEST..."
				$PROG $ARGS

				if [ $(uname) = "Linux" ];  then
					LEAKS=$(valgrind -q -- $PROG $ARGS)
					if [ $? ]; then
						success "\nNO LEAKS"
					else
						warning "\nLEAKS DETECTED"
					fi
					info "\nCHECKER PROVIDED"
					$PROG $ARGS | ./checker_linux $ARGS
				else
					LEAKS=$(leaks -atExit -quiet -- $PROG $ARGS)
					if [ $? ]; then
						success "\nNO LEAKS"
					else
						warning "\nLEAKS DETECTED"
						echo "$LEAKS"
					fi
					info "\nCHECKER PROVIDED"
					$PROG $ARGS | ./checker_Mac $ARGS
				fi

				info "\nCHECKER BONUS"
				$PROG $ARGS | $PROG_BONUS $ARGS
			fi
		fi
		sleep 0.1
	done
}

get_state() {
	if [[ $(uname) == "Linux" ]];  then
		MD5="md5sum"
	else
		MD5="md5"
	fi
	echo $(find -L . -type f -name "*.[ch]" -exec $MD5 {} \;)
}

watch

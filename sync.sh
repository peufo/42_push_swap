#!/bin/sh

sync() {

	#SYNC Makefile SOURCES
	SOURCES=$(ls src/*.c src/**/*.c | sed 's;src/;;g' | tr '\n' ' ')
	SOURCES_BONUS=$(ls bonus/*.c src/libft/*.c src/stack/*.c | sed 's;src/;;g' | sed 's;bonus/;;g' | tr '\n' ' ')

	SED_COMMAND="s;^SOURCES	.*;SOURCES		=	$SOURCES;"
	SED_COMMAND_BONUS="s;^SOURCES_BONUS	.*;SOURCES_BONUS	=	$SOURCES_BONUS;"
	if [ $(uname) = "Linux" ];  then
		sed -i -e "$SED_COMMAND" Makefile
		sed -i -e "$SED_COMMAND_BONUS" Makefile
	else
		sed -i "" "$SED_COMMAND" Makefile
		sed -i "" "$SED_COMMAND_BONUS" Makefile
	fi
}

sync "$@"

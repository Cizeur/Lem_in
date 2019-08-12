# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_one_map.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 17:57:30 by cgiron            #+#    #+#              #
#    Updated: 2019/08/12 10:33:22 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

################################ Functions #####################################

function usage() {
	printf "\nusage: sh ./test_one_map.sh [map] [-a number of ants] [-l options][-h usage]\n\n"
	printf "Lemin map test and displayer\n\
	- with  map\n\
	- with a amount of ants\
	- with -l or lemin options"
}

########################## Variables initialization ############################

map=$1
shift
ants=
program=./lem-in
visu=./visu_lemin
loptions="-es"
error=

############################# Options parser ###################################

while [ "$1" != "" ]; do
	OPT=$1
	case $OPT in
	-h | --help)
		usage
		exit 0
		;;
	-a)
		shift
		ants=$1
		;;
	-l)
		shift
		loptions=$1
		;;
	*)
		usage
		exit
		;;
	esac
	shift
done

################################ Main loop #####################################

usage

echo "\n\n MAP   :\033[0;32m" $map
echo "\033[0mlemin options :\033[0;32m" $loptions
echo "\033[0mAmount of ant given\033[0;32m" $ants
echo "\033[0m"

if test -f "$program"; then
	echo "\033[0;32m$program exist\033[0m"
else
	echo "\033[0;31m$program absent\033[0m"
	exit 1
fi
if [ ! -z "$ants" ]; then
	$program $loptions -a $ants <$map
	error=$($program -a $ants <$map | grep "ERROR")
else
	$program $loptions <$map
	error=$($program <$map | grep "ERROR")
fi
if [ ! -z "$error" ]; then
	exit
fi
echo "\n\n\033[0;32mWant to see the result ? \033[0m 0 [no] 1 [just active paths] 2 [Whole]\n\n"
read -p  "answer : " answer
if [ "$answer" == "1" ]; then
	if [ ! -z "$ants" ]; then
		$program -v -a $ants <$map | $visu&
	else
		$program -v <$map | $visu&
	fi
fi
if [ "$answer" == "2" ]; then
	if [ ! -z "$ants" ]; then
		$program -vu -a $ants <$map | $visu&
	else
		$program -vu <$map | $visu&
	fi
fi

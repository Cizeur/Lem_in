# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README_FORMAT_OUTPUT_LemIm.txt                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 10:14:44 by crfernan          #+#    #+#              #
#    Updated: 2019/07/16 10:25:25 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXAMPLE:

2
# number of nodes            = 5
# number of pipes            = 5
# number of inactive pipes   = 3
# number of movements        = 3
1 0 2
##start
0 2 0
##end
4 2 6
2 4 2
3 4 4
0-1
#inactive
0-2
#inactive
2-3
#inactive
3-4
4-1

L1-1
L1-4 L2-1
L2-4


INSTRUCTIONS:
    -   1st line: number of ants
    -   2nd line: string "# number of nodes            = " and the number of nodes
    -   3rd line: string "# number of pipes            = " and the number of pipes
    -   4th line: string "# number of inactive pipes   = " and the number of inactive pipes
        (the ones that we're not using at any path)
    -   5th line: string "# number of movements        = " and the number of movements
        needed to get all the ants to the end, has to be the same as he number of lines
        printed on the solution part (lines 36 37 38 at the example).
    
    -   NODES PART (lines 20 - 26 at the example): same format as the imput.
    
    -   PIPES PART (lines 27 - 34 at the example): same format as the imput, but printing a
        comment "#inactive" when the next pipe is not used at any path;
        at the example the line 28 indicates that the pipe of the line 29 (0-2) is not used.
    
    -   EMPTY LINE (line 35 at the example).

    -   SOLUTION PART (lines 36 - 38 at the example): format explained on the subject.

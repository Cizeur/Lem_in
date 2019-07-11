# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_visu_object.mk                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 12:48:07 by crfernan          #+#    #+#              #
#    Updated: 2019/07/11 18:11:30 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_exit.o: visu.h error.h
ft_get_movements.o: visu.h 
ft_get_nodes.o: visu.h
ft_get_pipes.o: visu.h 
ft_get_input.o: visu.h 
ft_print.o: visu.h
initialization.o: visu.h 
main.o: visu.h 
parser.o: visu.h libft/get_next_line.h
visual.o: visu.h 
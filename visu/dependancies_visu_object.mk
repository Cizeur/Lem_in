# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_visu_object.mk                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 12:48:07 by crfernan          #+#    #+#              #
#    Updated: 2019/08/06 20:10:59 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_exit.o: visu.h error.h
ft_get_moves.o: visu.h 
ft_get_nodes.o: visu.h
ft_get_pipes.o: visu.h 
ft_get_input.o: visu.h 
ft_print.o: visu.h
initialization.o: visu.h 
main.o: visu.h 
parser.o: visu.h libft/get_next_line.h
T_init.o: visu.h
T_load_media.o: visu.h
T_load_texture.o: visu.h
T_run.o: visu.h
T_close.o: visu.h
T_texture.o: visu.h
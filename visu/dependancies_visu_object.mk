# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_visu_object.mk                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 12:48:07 by crfernan          #+#    #+#              #
#    Updated: 2019/07/18 16:44:46 by crfernan         ###   ########.fr        #
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
visual.o: visu.h key_press.h
T_init_visual.o: visu.h
T_load_visual.o: visu.h
T_load_surface_visual.o: visu.h
T_load_texture_visual.o: visu.h
T_run_visual.o: visu.h
T_close_visual.o: visu.h
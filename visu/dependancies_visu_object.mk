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

close.o: visu.h libft/libft.h
control.o: visu.h key_press.h
free.o: visu.h libft/libft.h
ft_check.o: visu.h libft/get_next_line.h
ft_exit.o: visu.h libft/libft.h error.h
ft_get_input.o: visu.h libft/libft.h
ft_get_moves.o: visu.h libft/libft.h
ft_get_nodes.o: visu.h libft/libft.h
ft_get_pipes.o: visu.h libft/libft.h
initialization.o: visu.h libft/libft.h
main.o: visu.h libft/libft.h
parser.o: visu.h libft/libft.h libft/get_next_line.h
print.o: visu.h
utils.o: visu.h libft/libft.h
visu_init.o: visu.h
visu_load.o: visu.h libft/libft.h
visu_render_moves.o: visu.h
visu_render_nodes.o: visu.h
visu_render_pipes.o: visu.h
visu_render_total_background.o: visu.h
visu_run.o: visu.h
visu_texture.o: visu.h libft/libft.h

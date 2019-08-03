# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_lemin_object.mk                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 12:24:56 by cgiron            #+#    #+#              #
#    Updated: 2019/07/05 15:38:11 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_dico_add.o: lem_in.h libft/libft.h
ft_exit.o: error.h lem_in.h
ft_find_start.o: utils.h
ft_init_mstr.o: lem_in.h error.h libft/libft.h
ft_parser_ants_get.o: error.h libft/libft.h libft/get_next_line.h utils.h lem_in.h
ft_parser_check_cell.o: lem_in.h libft/libft.h utils.h
ft_parser_line_type.o: libft/libft.h lem_in.h utils.h
ft_storage_add_line.o: lem_in.h
ft_storage_comment_addend.o: lem_in.h
ft_storage_grow.o: libft/libft.h lem_in.h error.h
main.o: lem_in.h libft/libft.h
parser.o: libft/get_next_line.h lem_in.h

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_lemin.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 11:46:32 by cgiron            #+#    #+#              #
#    Updated: 2019/07/08 13:51:36 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_LEMIN_DEP := 1

L_LEMIN_DIR	:= lemin

NAME_LEMIN	:= lem-in

SRC_LEMIN =  \
	parser.c\
	ft_parser_ants_get.c\
	ft_parser_line_type.c\
	ft_parser_check_node.c\
	ft_parser_check_pipe.c\
	ft_parser_fill_entry_node.c\
	ft_storage_grow.c\
	ft_storage_add_line.c\
	ft_is_whitespace.c\
	ft_find_end.c\
	ft_init_mstr.c\
	ft_exit.c\
	main.c\
	ft_dico_hasher_djb2.c
	##ft_dico_add.c\

INC_LEMIN					:= lem_in.h\
							error.h\
							libft/get_next_line.h\
							libft/libft.h

DEPENDANCIES_LEMIN_O		:= Makefile ./dependancies_$(L_LEMIN_DIR).mk\
								 ./dependancies_$(L_LEMIN_DIR)_object.mk\
								 ../shared_val.mk


DEPENDANCIES_LEMIN_O		+= ./includes/*.h


DEPENDANCIES_LEMIN			:= $(DEPENDANCIES_LEMIN_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_LEMIN_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_LEMIN))
SRC_LEMIN_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_LEMIN))
DEPENDANCIES_LEMIN_E 		:= $(DEPENDANCIES_LEMIN) $(SRC_LEMIN_EXPORT) $(INC_LEMIN_EXPORT)
DEPENDANCIES_LEMIN_EXPORT	:= $(addprefix $(L_LEMIN_DIR)/,$(DEPENDANCIES_LEMIN_E))

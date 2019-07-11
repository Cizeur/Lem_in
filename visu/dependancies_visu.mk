# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_visu.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 12:40:40 by crfernan          #+#    #+#              #
#    Updated: 2019/07/11 16:06:14 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif

CHECK_VISU_DEP := 1

L_VISU_DIR	:= visu

NAME_VISU	:= visu

SRC_VISU =  \
	parser.c \
	ft_exit.c \
	ft_get_input.c \
	ft_get_movements.c \
	ft_get_nodes.c \
	ft_get_pipes.c \
	ft_print.c \
	initialization.c \
	main.c \
	visual.c

INC_VISU					:= visu.h\
							error.h\
							libft/get_next_line.h\
							libft/libft.h

DEPENDANCIES_VISU_O		:= Makefile ./dependancies_$(L_VISU_DIR).mk\
								 ./dependancies_$(L_VISU_DIR)_object.mk\
								 ../shared_val.mk

DEPENDANCIES_VISU_O		+= ./includes/*.h

DEPENDANCIES_VISU			:= $(DEPENDANCIES_LEMIN_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_VISU_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_VISU))
SRC_VISU_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_VISU))
DEPENDANCIES_VISU_E 		:= $(DEPENDANCIES_VISU) $(SRC_VISU_EXPORT) $(INC_VISU_EXPORT)
DEPENDANCIES_VISU_EXPORT	:= $(addprefix $(L_VISU_DIR)/,$(DEPENDANCIES_VISU_E))

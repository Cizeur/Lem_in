# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    share_flags.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 09:36:56 by cgiron            #+#    #+#              #
#    Updated: 2019/08/06 18:47:58 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK_SHARED_VAL		:= 1
SHARE_SRC_DIR			:= src
SHARE_OBJ_DIR			:= obj
SHARE_INC_DIR			:= includes

vpath %.c $(SHARE_SRC_DIR)
vpath %.h $(SHARE_INC_DIR)
vpath %.o $(SHARE_OBJ_DIR)

SHARE_FLAGS				:= -Wall -Wextra -Werror
#SHARE_FLAGS				+= -O3 -ffreestanding -fno-builtin -flto
SHARE_FLAGS				+= -I $(SHARE_INC_DIR)
SHARE_DEBUG				:= -O0 -g3

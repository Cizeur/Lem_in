# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:45 by crfernan          #+#    #+#              #
#    Updated: 2019/07/31 12:08:01 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_visu.mk
include ../libft/dependancies_libft.mk
include ../shared_val.mk

ifeq ($(CHECK_VISU_DEP),)
	$(error_VISU_DEPENDANCIES not included)
endif
ifeq ($(CHECK_SHARED_VAL),)
	$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
	$(error LIBFT_DEPENDANCIES not included)
endif

DEPENDANCY_OBJ_INC_FILE := ./dependancies_$(L_VISU_DIR)_object.mk

L_FT    := ../libft

SDL_IFLAGS	:=	-I../frameworks/SDL2.framework/Versions/A/Headers \
				-I../frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I../frameworks/SDL2_image.framework/Versions/A/Headers \
				-F../frameworks
SDL_EXFLAGS	+=	-F../frameworks \
				-rpath ../frameworks\
				-rpath ./frameworks\
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \

EXFLAGS := -L $(L_FT) -lft

SIMULINK := $(SHARE_INC_DIR)/$(NAME_LIBFT)

NAME 	:= $(NAME_VISU)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_VISU)
OBJ		:= $(patsubst %.c,%.o,$(SRC))

CC      := gcc
CFLAGS  := $(SHARE_FLAGS) 
CFLAGS	+= $(SDL_IFLAGS)
EXFLAGS	+= $(SDL_EXFLAGS)

.PHONY: all clean fclean re debug simulink

all: $(NAME)

simulink:
	rm -rf	$(INC_DIR)/$(L_LIBFT_DIR)
	ln -s	../$(L_FT)/$(INC_DIR) $(INC_DIR)/$(L_LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_VISU_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -g -c $< -o $(OBJ_DIR)/$@

-include $(DEPENDANCY_OBJ_INC_FILE)

$(NAME): $(OBJ) $(DEPENDANCIES_VISU)
	$(MAKE) -C $(L_FT) "CFLAGS=$(CFLAGS)" --no-print-directory
	$(CC)  $(EXFLAGS)  $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(NAME)

clean:
	$(MAKE) clean -C $(L_FT) --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(L_FT) --no-print-directory
	rm -f $(NAME)

debug: CFLAGS += $(SHARE_DEBUG)
debug: re clean

re: fclean all

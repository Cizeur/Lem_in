# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:45 by crfernan          #+#    #+#              #
#    Updated: 2019/07/24 16:17:51 by crfernan         ###   ########.fr        #
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

L_SDL			:= /Users/crfernan/.brew/Cellar/sdl2/2.0.9_1/lib
L_SDL_DIR		:= /Users/crfernan/.brew/Cellar/sdl2/2.0.9_1/include/SDL2/

L_SDL_TTF		:= /Users/crfernan/.brew/Cellar/sdl2_ttf/2.0.15/lib
L_SDL_TTF_DIR	:= /Users/crfernan/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2/

L_SDL_GLX		:= /Users/crfernan/.brew/Cellar/sdl2_gfx/1.0.4/lib
L_SDL_GLX_DIR	:= /Users/crfernan/.brew/Cellar/sdl2_gfx/1.0.4/include/SDL2/

L_SDL_IMAGE		:= /Users/crfernan/.brew/Cellar/sdl2_image/2.0.5/lib
L_SDL_IMAGE_DIR	:= /Users/crfernan/.brew/Cellar/sdl2_image/2.0.5/include/SDL2/

EXFLAGS := -L $(L_FT) -lft -L $(L_SDL) -lSDL2 -L $(L_SDL_TTF) -lSDL2_ttf
EXFLAGS += -L $(L_SDL_GLX) -lSDL2_gfx -L $(L_SDL_IMAGE) -lSDL2_image

SIMULINK := $(SHARE_INC_DIR)/$(NAME_LIBFT)

NAME 	:= $(NAME_VISU)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_VISU)
OBJ		:= $(patsubst %.c,%.o,$(SRC))

CC      := gcc
CFLAGS  := $(SHARE_FLAGS) -I $(L_SDL_DIR) -I $(L_SDL_TTF_DIR)
CFLAGS	+= -I $(L_SDL_GLX_DIR) -I $(L_SDL_IMAGE_DIR)

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

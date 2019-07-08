# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:16:41 by cgiron            #+#    #+#              #
#    Updated: 2019/06/19 17:16:41 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./libft/dependancies_libft.mk
include ./shared_val.mk

ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
$(error LIBFT_DEPENDANCIES not included)
endif

NAME := $(NAME_LEMIN)

L_NAME = "NAME_LEMIN=../$(NAME_LEMIN)"

.PHONY: all clean fclean re debug

all : $(NAME)

STD_DEPENDANCY := $(DEPENDANCIES_LIBFT_EXPORT)

$(NAME_LEMIN) : $(DEPENDANCIES_LEMIN_EXPORT) $(STD_DEPENDANCY)
	@$(MAKE) -C $(L_LEMIN_DIR) $(L_NAME) --no-print-directory

clean:
	$(MAKE) clean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) clean -C $(L_LEMIN_DIR) --no-print-directory

fclean:
	$(MAKE) fclean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_LEMIN_DIR) --no-print-directory
	rm -f $(L_LEMIN_DIR)/$(NAME_LEMIN)
	rm -f $(NAME)

simulink:
	$(MAKE) simulink -C $(L_LEMIN_DIR) --no-print-directory

debug:
	$(MAKE) debug -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) debug -C $(L_LEMIN_DIR) $(C_NAME) --no-print-directory

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/02/14 17:50:59 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME		= puissance4
SRCS		= srcs/puissance4.c srcs/ft_print.c srcs/ft_check_win.c \
			  srcs/ft_check_error.c srcs/ft_color.c srcs/ft_restart.c
INCLUDES	= ./includes
LIBFT		= ./libft/libft.a
OBJ			= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror

##################
##    COLORS    ##
##################

_BLACK		=$ \033[30m
_RED		=$ \033[31m
_GREEN		=$ \033[32m
_YELLOW		=$ \033[33m
_BLUE		=$ \033[34m
_VIOLET		=$ \033[35m
_CYAN		=$ \033[36m
_WHITE		=$ \033[37m
_END		=$ \033[0m
_CLEAR		=$ \033[2K

##################
##   TARGETS    ##
##################

.PHONY: all libft clean fclean re

all: libft $(NAME)

libft:
	@make -C libft all

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@printf "$(_GREEN) Done.\n$(_END)"

%.o: %.c
	@gcc $(FLAGS) -I $(INCLUDES) -c $^ -o $@
	@printf "$(_YELLOW) building - $(_END)"
	@printf "$(_GREEN)"
	@printf $@ | cut -c6- | cut -d'.' -f1
	@printf "$(_END)"

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

lynux:
	@make -C libft lynux

booh:
	@make -C libft booh

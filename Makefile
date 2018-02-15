# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:44:25 by bede-fre          #+#    #+#              #
#    Updated: 2018/02/15 12:17:16 by bede-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
SRC = sources/main2.c sources/ft_free_list.c sources/ft_read_stock.c
INCLUDES = ./includes
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

_GREY		=$ \033[30m
_RED		=$ \033[31m
_GREEN		=$ \033[32m
_YELLOW		=$ \033[33m
_BLUE		=$ \033[34m
_PURPLE		=$ \033[35m
_CYAN		=$ \033[36m
_WHITE		=$ \033[37m
_END		=$ \033[0m
_BOLD		=$ \033[1m
_CLEAR		=$ \033[2K
_SAVE		=$ \033[7
_BACK		=$ \033[8
_HIDE_CURS	=$ \033[?25l
_SHOW_CURS	=$ \033[?25h

.PHONY: all libft clean fclean re

all: libft $(NAME)

libft:
	@make -C libft

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework Appkit $(OBJ) $(LIBFT) -o $(NAME)
	@printf "$(_CLEAR)$(_CYAN)# EXECUTABLE FILE CREATION # $(_GREEN)fdf\n$(_END)"
	@printf "$(_GREEN)# EXECUTABLE FILE CREATED #\n$(_END)$(_SHOW_CURS)"

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $^ -o $@
	@printf "$(_CLEAR)$(_CYAN)# EXECUTABLE FILE CREATION # $(_END)"
	@printf "$(_YELLOW)$@$(_END)"
	@printf "$(_HIDE_CURS)\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)
	@printf "$(_RED)# DELETE EXECUTABLE OBJECT FILES #\n$(_END)"


fclean: clean
	@/bin/rm -f $(NAME) $(LIBFT)
	@printf "$(_RED)# DELETE LIBRARY FILE #\n$(_END)"
	@printf "$(_RED)# DELETE EXECUTABLE FILE #\n$(_END)"

re: fclean all

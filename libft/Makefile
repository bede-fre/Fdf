# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:44:25 by bede-fre          #+#    #+#              #
#    Updated: 2018/03/06 15:24:11 by bede-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC		= clang
FLAGS		= -Wall -Wextra -Werror -g
SRC 		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_islower.c ft_isupper.c \
			ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
			ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
			ft_tolower.c ft_toupper.c ft_strrev.c ft_abs.c \
			ft_islower.c ft_isupper.c ft_lstnew.c ft_lstdelone.c \
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
			ft_strndup.c ft_realloc.c ft_itoa_base.c ft_gnl.c \
			ft_isspace.c ft_split_whitespaces.c ft_atoi_base.c \
			ft_power.c ft_atol.c ft_error.c ft_putnbr.c
OBJ		= $(SRC:.c=.o)

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

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "$(_CLEAR)$(_CYAN)# LIBRARY FILE CREATION # $(_GREEN)libft.a\n$(_END)"
	@printf "$(_GREEN)# LIBRARY FILE CREATED #\n$(_END)$(_SHOW_CURS)"

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@
	@printf "$(_CLEAR)$(_CYAN)# LIBRARY FILE CREATION # $(_END)"
	@printf "$(_YELLOW)$@$(_END)"
	@printf "$(_HIDE_CURS)\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"

clean:
	@/bin/rm -f $(OBJ)
	@printf "$(_RED)# DELETE LIBRARY OBJECT FILES #\n$(_END)"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "$(_RED)# DELETE LIBRARY FILE #\n$(_END)"

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:56:29 by kaheinz           #+#    #+#              #
#    Updated: 2022/06/06 19:00:31 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = push_swap.h

SRCS = push_swap.c error_handler.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

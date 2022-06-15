# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 18:56:29 by kaheinz           #+#    #+#              #
#    Updated: 2022/06/11 17:09:12 by kaheinz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = push_swap.h

SRCS = push_swap.c pushing.c swap.c rotate.c reverse_rotate.c error_handler.c list_handling.c\

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g

$(NAME): $(OBJS)
	make -C libft/
	make bonus -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re

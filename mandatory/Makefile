# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahi <amahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 02:05:54 by amahi             #+#    #+#              #
#    Updated: 2022/04/05 02:16:32 by amahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	push_swap

HEADER	=	push_swap.h

FLAGS 	=	-Wextra -Werror -Wall
# FLAGS =	-Wextra -Werror -Wall -fsanitize=address -fsanitize=undefined

SOURCE	=	push_swap.c		errors.c		\
			swap.c			good_massiv.c	\
			list.c			put.c			\
			rotate.c		reverse_rotate.c\
			src.c			mini_sort.c		\
			big_sort.c

OBJECT	=	$(SOURCE:.c=.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJECT)
			$(CC) $(OBJECT) -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJECT)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

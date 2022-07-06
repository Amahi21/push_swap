# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amahi <amahi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 12:22:29 by amahi             #+#    #+#              #
#    Updated: 2022/07/05 20:22:45 by amahi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	checker

HEADER	=	checker.h get_next_line.h

FLAGS 	=	-Wextra -Werror -Wall
# FLAGS =	-Wextra -Werror -Wall -fsanitize=address -fsanitize=undefined

SOURCE	=	main.c					check.c			\
			list.c					get_next_line.c	\
			get_next_line_utils.c	put.c			\
			reverse_rotate.c		rotate.c		\
			swap.c

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

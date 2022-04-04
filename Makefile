NAME = push_swap

FLAGS = -Wextra -Werror -Wall -fsanitize=address

LIST =	push_swap.c		errors.c		\
		swap.c			good_massiv.c	\
		list.c			put.c			\
		rotate.c		reverse_rotate.c\
		src.c			mini_sort.c		\
		big_sort.c

OBJECT	=	$(LIST:.c=.o)

all		:	
			$(CC) $(LIST) $(FALGS) -o $(NAME)

%.o		:	%.c
			$(CC) $(FALGS) -o $(NAME)

clean	:
			rm -f ()
			rm -f push_swap

####################
####	FLAGS	####
####################
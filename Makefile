NAME = push_swap

FLAGS = -Wextra -Werror -Wall

LIST =	push_swap.c		errors.c		\
		swap.c			good_massiv.c	\
		list.c			put.c			\
		rotate.c		reverse_rotate.c\
		src.c			mini_sort.c		\
		big_sort.c

all:	
	gcc $(LIST) -o $(NAME)

clean:
	rm -f push_swap

####################
####	FLAGS	####
####################
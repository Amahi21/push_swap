/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:02:09 by amahi             #+#    #+#             */
/*   Updated: 2022/03/29 23:43:37 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_list
{
	int				value;
	int				index;
	struct s_list 	*next;
}	t_list;

typedef struct s_info
{
	int min;
	int med;
	int max;

	int	ac;
}	t_info;

// push_swap.c
void	out(t_list *stack_a, t_list *stack_b, t_info *info);

// errors.c
void	errors(char *s);

// good_massiv.c
int		form_char_to_int(char *s);
void	dublucate(char **av);
// void	sortes_checker(t_list **stack);

// src.c
int		len_av(char **s);
int		len_list(t_list **stack);
int		*sorted_massiv(char **av, int ac, t_info *info);

// list.c
t_list	*init_list(int value, int index);
void	add_elem_back(t_list **head, t_list *new);

// swap.c
void	sa(t_list **head);
void	sb(t_list **head);
void	ss(t_list **head_a, t_list **head_b);

// push.c
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// rotate.c
void	rotate(t_list **head);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// reverse.c
void	reverse_rotate(t_list **head);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// mini_sort.c
void	sort_3(t_list **stack_a, t_info *info);
void	sort_5_push_b(t_list **stack_a, t_list **stack_b, int num);

// big_sort.c
int		number(int n);
void	push_b(t_list **stack_a, t_list **stack_b, t_info *info);
void	sort(int n, int i, t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b, t_info *info);

#endif // PUSH_SWAP

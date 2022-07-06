/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:23:25 by amahi             #+#    #+#             */
/*   Updated: 2022/07/06 15:17:29 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;

}	t_list;

// main.c
void	error(char *text);

// get_next_line.c
char	*get_next_line(int fd);

// check.c
void	check_input(char **av);
void	dublucate(char **av);
int		form_char_to_int(char *s);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

// list.c
t_list	*init_elem(int value);
void	add_elem_back(t_list *head, t_list *new);
t_list	*create_list(t_list *list, char **av, int ac);

// reverse_rotate.c
void	reverse_rotate(t_list *head);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *stack_b);

// rotate.c
void	rotate(t_list *head);
void	rra(t_list *stack_a);
void	rrb(t_list *stack_b);
void	rrr(t_list *stack_a, t_list *stack_b);

// push.c
void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);

// swap.c
void	sa(t_list *head);
void	sb(t_list *head);
void	ss(t_list *head_a, t_list *head_b);

#endif
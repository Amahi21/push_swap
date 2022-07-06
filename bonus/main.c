/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:23:10 by amahi             #+#    #+#             */
/*   Updated: 2022/07/06 15:24:17 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(char *text)
{
	int	i;

	i = 0;
	while (text[i])
		write(1, &text[i++], 1);
	write(1, "\n", 1);
	exit(1);
}

void	action(char *str, t_list *a, t_list *b)
{
	if (ft_strncmp(str, "ra\n", 3))
		ra(a);
	else if (ft_strncmp(str, "rb\n", 3))
		rb(b);
	else if (ft_strncmp(str, "rr\n", 3))
		rr(a, b);
	else if (ft_strncmp(str, "rra\n", 4))
		rra(a);
	else if (ft_strncmp(str, "rrb\n", 4))
		rrb(b);
	else if (ft_strncmp(str, "rrr\n", 4))
		rrr(a, b);
	else if (ft_strncmp(str, "pa\n", 3))
		pa(a, b);
	else if (ft_strncmp(str, "pb\n", 3))
		pb(a, b);
	else if (ft_strncmp(str, "sa\n", 3))
		sa(a);
	else if (ft_strncmp(str, "sb\n", 3))
		sb(b);
	else if (ft_strncmp(str, "ss\n", 3))
		ss(a, b);
}

void	check_sorted(t_list *a)
{
	while (a->next)
	{
		printf("Here\n");
		printf("a - %d\n", a->value);
		if (a->value < a->next->value)
			a = a->next;
		else
			error("KO");
	}
	error("OK");
}

void	run(t_list *a, t_list *b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		action(str, a, b);
		str = get_next_line(0);
	}
	while (a)
	{
		printf("a - %d\n", a->value);
		a = a->next;
	}
	check_sorted(a);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		check_input(av);
		dublucate(av);
		stack_a = create_list(stack_a, av, ac);
		
		run(stack_a, stack_b);
	}
	else
		error("Error!");
	return (0);
}

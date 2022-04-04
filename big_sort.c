/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:31:40 by amahi             #+#    #+#             */
/*   Updated: 2022/03/29 23:38:14 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number(int n)
{
	int	res;

	res = 12;
	while (n > 0)
	{
		if (n % 27 == 0)
			res++;
		n--;
	}
	return (res);
}

void	push_b(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int	counter;

	counter = 0;
	while ((*stack_a))
	{
		if ((*stack_a)->index <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if ((*stack_a)->index <= counter + number(info->ac))
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
	
}

void	sort(int n, int i, t_list **stack_a, t_list **stack_b)
{
	if (i >= (n / 2))
	{
		while ((*stack_b)->index != n)
			rrb(stack_b);
	}
	else
	{
		while ((*stack_b)->index != n)
			rb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	big_sort(t_list **stack_a, t_list **stack_b, t_info *info)
{
	int		i;
	int		n;
	t_list	*tmp;
	push_b(stack_a, stack_b, info);

	n = len_list(stack_b);
	while ((*stack_b))
	{
		i = 0;
		tmp = *stack_b;
		while (tmp->index != n)
		{
			tmp = tmp->next;
			i++;
		}
		sort(n, i, stack_a, stack_b);
		i = 0;
		n--;
	}
}

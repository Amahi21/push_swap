/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:07:26 by amahi             #+#    #+#             */
/*   Updated: 2022/04/05 01:54:48 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a, t_info *info)
{
	if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index)
		return ;
	if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		rra(stack_a);
	else if ((*stack_a)->next->next->index < (*stack_a)->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index)
		ra(stack_a);
	else
	{
		sa(stack_a);
		sort_3(stack_a, info);
	}
}

void	r_score(t_list **stack_a, int score, int len)
{
	if (score < 3)
	{
		while (score != 1)
		{
			ra(stack_a);
			score--;
		}	
	}
	else
	{
		while (score != len + 1)
		{
			rra(stack_a);
			score++;
		}	
	}
}

void	sort_5_push_b(t_list **stack_a, t_list **stack_b, int num)
{
	int		score;
	int		len;
	t_list	*tmp;

	score = 1;
	tmp = *stack_a;
	len = len_list(stack_a);
	while ((*stack_a)->value != num)
	{
		(*stack_a) = (*stack_a)->next;
		score++;
	}
	*stack_a = tmp;
	r_score(stack_a, score, len);
	pb(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b, t_info *info)
{
	sort_5_push_b(stack_a, stack_b, info->max);
	sort_5_push_b(stack_a, stack_b, info->min);
	sort_3(stack_a, info);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

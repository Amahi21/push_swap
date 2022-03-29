/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:07:26 by amahi             #+#    #+#             */
/*   Updated: 2022/03/27 22:21:44 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a, t_info *info)
{
	if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index)
		return ;
	if ((*stack_a)->next->index < (*stack_a)->next->next->index
		&& (*stack_a)->next->next->index < (*stack_a)->index)
		ra(stack_a);
	else if ((*stack_a)->next->index < (*stack_a)->next->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		rra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else
	{
		sa(stack_a);
		sort_3(stack_a, info);
	}
}

void	sort_5_push_b(t_list **stack_a, t_list **stack_b, int num)
{
	int score;
	int	len;
	t_list *tmp;

	score = 1;

	tmp = *stack_a;
	len = len_list(stack_a);
	while ((*stack_a)->value != num)
	{
		(*stack_a) = (*stack_a)->next;
		score++;
	}
	*stack_a = tmp;
	if (score < 3)
		while (score != 1)
		{
			ra(stack_a);
			score--;
		}
	else
		while (score != len + 1)
		{
			rra(stack_a);
			score++;
		}
	pb(stack_a, stack_b);
}

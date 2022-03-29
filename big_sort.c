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

void put_3m(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list *tmp;

	while (*stack_a)
	{
		if (len_list(stack_a) == 3)
			break;
		if ((*stack_a)->value == info->max || (*stack_a)->value == info->med || (*stack_a)->value == info->min)
		{
			tmp = (*stack_a)->next;
			ra(stack_a);
			*stack_a = tmp;
		}
		else
			pb(stack_a, stack_b);
	}
	sort_3(stack_a, info);
}

void	move(t_list **stack_a, t_list **stack_b, t_info *info)
{
	
}

void	buffer(int a, int b, t_info *info)
{
	info->a = a;
	info->b = b;
	if (a + b < info->sum)
		info->sum = a + b;
	else if (a + info->len_b - b < info->sum)
		info->sum = a + info->len_b - b;
	else if (info->len_a - a + b < info->sum)
		info->sum = info->len_a - a + b;
	else if (info->len_a - a + info->len_b - b < info->sum)
		info->sum = info->len_a - a + info->len_b - b;
	if (a < info->len_a / 2 && b < info->len_b / 2)
		info->flag = 1;
	else if (a >= info->len_a / 2 && b < info->len_b / 2)
		info->flag = 2;
	else if (a < info->len_a / 2 && b >= info->len_b / 2)
		info->flag = 3;
	else if (a >= info->len_a / 2 && b >= info->len_b / 2)
		info->flag = 4;
}

void	score(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		a;
	int		b;

	a = 0;
	tmpa = *stack_a;
	while (tmpa->next)
	{
		b = 0;
		tmpb = *stack_b;
		while (tmpb->next)
		{
			if (tmpb->index > tmpa->index && tmpb->index < tmpa->next->index)
					buffer(a, b, info);
			b++;
			tmpb = tmpb->next;
		}
		a++;
		tmpa = tmpa->next;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, t_info *info)
{
	put_3m(stack_a, stack_b, info);
	while (*stack_b)
	{
		info->len_a = len_list(stack_a);
		info->len_b = len_list(stack_b);
		info->sum = INT_MAX;
		score(stack_a, stack_b, info);
	}
}
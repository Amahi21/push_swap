/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:41 by amahi             #+#    #+#             */
/*   Updated: 2022/03/27 18:10:12 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b)
		return ;
	write(1, "pa\n", 3);
	put(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	write(1, "pb\n", 3);
	put(stack_b, stack_a);
}
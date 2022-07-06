/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:46 by amahi             #+#    #+#             */
/*   Updated: 2022/07/06 15:15:16 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list *head)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = head;
	tmp1 = head->next;
	while (head->next)
		head = head->next;
	head->next = tmp;
	tmp->next = NULL;
	head = tmp1;
}

void	rra(t_list *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_list *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

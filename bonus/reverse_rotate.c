/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:43 by amahi             #+#    #+#             */
/*   Updated: 2022/07/06 15:14:14 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_list *head)
{
	t_list	*first;
	t_list	*end;

	if (head && head->next)
	{
		end = head;
		while (end != NULL)
		{
			if (end->next->next == NULL)
			{
				first = end->next;
				end->next = NULL;
			}
			end = end->next;
		}
		first->next = head;
		head = first;
	}
}

void	ra(t_list *stack_a)
{
	rotate(stack_a);
}

void	rb(t_list *stack_b)
{
	rotate(stack_b);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

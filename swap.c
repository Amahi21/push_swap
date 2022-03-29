/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:52 by amahi             #+#    #+#             */
/*   Updated: 2022/03/27 18:13:47 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list **head)
{
	t_list	*tmp;

	tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	tmp->next = *head;
	return (tmp);
}

void	sa(t_list **head)
{
	if (!head || !(*head)->next)
		return ;
	write(1, "sa\n", 3);
	(*head) = swap(head);
}

void	sb(t_list **head)
{
	if (!head || !(*head)->next)
		return ;
	write(1, "sb\n", 3);
	(*head) = swap(head);
}

void	ss(t_list **head_a, t_list **head_b)
{
	(*head_a) = swap(head_a);
	(*head_b) = swap(head_b);
	write(1, "ss\n", 3);
}
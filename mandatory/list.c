/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:34 by amahi             #+#    #+#             */
/*   Updated: 2022/04/04 19:42:03 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(int value, int index)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->index = index;
	list->value = value;
	list->next = NULL;
	return (list);
}

void	add_elem_back(t_list **head, t_list *new)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

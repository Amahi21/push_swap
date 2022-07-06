/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:52:08 by amahi             #+#    #+#             */
/*   Updated: 2022/07/05 20:26:33 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*init_elem(int value)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->value = value;
	list->next = NULL;
	return (list);
}

void	add_elem_back(t_list *head, t_list *new)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*create_list(t_list *list, char **av, int ac)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < ac)
	{
		new = init_elem(form_char_to_int(av[i]));
		if (i == 1)
			list = new;
		else
			add_elem_back(list, new);
		i++;
	}
	return (list);
}

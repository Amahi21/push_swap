/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:49 by amahi             #+#    #+#             */
/*   Updated: 2022/03/29 23:35:53 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_av(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i - 1);
}

int	len_list(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	i += 1;
	return (i);
}

int	*sorted_massiv(char **av, int ac, t_info *info)
{
	int	i;
	int	j;
	int	*tmp_str;
	int	tmp;

	i = 1;
	j = 0;
	tmp_str = (int *)malloc((ac) * sizeof(int));
	while (av[i])
		tmp_str[j++] = form_char_to_int(av[i++]);
	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tmp_str[i] > tmp_str[j])
			{
				tmp = tmp_str[i];
				tmp_str[i] = tmp_str[j];
				tmp_str[j] = tmp;
			}
			j++;
		}
		i++;
	}
	info->max = tmp_str[ac - 2];
	info->med = tmp_str[j / 2];
	info->min = tmp_str[0];
	return (tmp_str);
}

void	null(t_info *info)
{
	info->ra = 0;
	info->rra = 0;
	info->rb = 0;
	info->rrb = 0;
	info->sum = INT_MAX;
}

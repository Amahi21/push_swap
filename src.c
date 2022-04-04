/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:49 by amahi             #+#    #+#             */
/*   Updated: 2022/04/04 20:06:04 by amahi            ###   ########.fr       */
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

int	*init_mass(char **av, int ac)
{
	int	*tmp_str;
	int	i;
	int	j;

	j = 0;
	i = 1;
	tmp_str = (int *)malloc((ac) * sizeof(int));
	while (av[i])
		tmp_str[j++] = form_char_to_int(av[i++]);
	return (tmp_str);
}

int	*sorted_massiv(char **av, int ac, t_info *info)
{
	int	*tmp_str;
	int	tmp;

	tmp_str = init_mass(av, ac);
	info->i = 0;
	while (info->i < ac - 1)
	{
		info->j = info->i + 1;
		while (info->j < ac - 1)
		{
			if (tmp_str[info->i] > tmp_str[info->j])
			{
				tmp = tmp_str[info->i];
				tmp_str[info->i] = tmp_str[info->j];
				tmp_str[info->j] = tmp;
			}
			info->j++;
		}
		info->i++;
	}
	info->max = tmp_str[ac - 2];
	info->med = tmp_str[info->j / 2];
	info->min = tmp_str[0];
	return (tmp_str);
}

void	free_stack(t_list *stack)
{
	t_list	*this;

	while (stack)
	{
		this = stack;
		stack = stack->next;
		free(this);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_massiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:32 by amahi             #+#    #+#             */
/*   Updated: 2022/04/05 01:30:13 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *first)
{
	t_list	*stack;

	stack = first;
	while (stack->next)
	{
		if (stack->index >= stack->next->index)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	form_char_to_int(char *s)
{
	int		i;
	int		neg;
	long	tmp;

	i = 0;
	neg = 1;
	tmp = 0;
	if (s[0] == '-' && s[1] != '\0')
	{
		neg = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			tmp = tmp * 10 + s[i] - '0';
			if (tmp * neg > __INT_MAX__ || tmp * neg < -__INT_MAX__ - 1)
				errors("Error1");
		}
		else
			errors("Error");
		i++;
	}
	return ((int)tmp * neg);
}

void	dublucate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		if (av[i][0] == '\0')
			errors("Error");
		while (av[j])
		{
			if (form_char_to_int(av[i]) == form_char_to_int(av[j]) && i != j)
				errors("Error");
			j++;
		}
		i++;
	}
}

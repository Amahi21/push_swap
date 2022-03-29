/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_massiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:32 by amahi             #+#    #+#             */
/*   Updated: 2022/03/27 17:11:00 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int form_char_to_int(char *s)
{
	int i;
	int neg;
	long tmp;

	i = 0;
	neg = 1;
	tmp = 0;
	if (s[0] == '-')
	{
		neg = -1;
		i++;
	}
	while(s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			tmp = tmp * 10 + s[i] - '0';
			if (tmp > INT_MAX || tmp < INT_MIN)
				errors("Error range of INT");
		}
		else
			errors("ALLARM!!!! CHAR WAS FOUNDED!");
		i++;
	}
	return ((int)tmp * neg);
}

void	dublucate(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while(av[j])
		{
			if (form_char_to_int(av[i]) == form_char_to_int(av[j]) && i != j)
				errors("Error: Dublucate");
			j++;
		}
		i++;
	}
}

// void	sortes_checker(t_list **stack)
// {
// 	t_list *tmp;

// 	tmp = *stack;
// 	while ((*stack)->index < (*stack)->next->index && (*stack)->next->next)
// 	{
// 		if ((*stack)->next->next == NULL)
// 			errors("Sorted");
// 		(*stack) = (*stack)->next;
// 	}
// 	*stack = tmp;
// }
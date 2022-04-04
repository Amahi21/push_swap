/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:02:05 by amahi             #+#    #+#             */
/*   Updated: 2022/04/05 01:39:01 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_all(int ac, char **av, t_list *stack_a, t_info *info)
{
	t_list		*new;
	int			*sorted_mass;

	sorted_mass = sorted_massiv(av, ac, info);
	info->i = 1;
	while (info->i < ac)
	{
		info->j = 0;
		while (info->j < ac - 1)
		{
			if (form_char_to_int(av[info->i]) == sorted_mass[info->j])
			{
				new = init_list(form_char_to_int(av[info->i]), info->j + 1);
				if (info->i == 1)
					stack_a = new;
				else
					add_elem_back(&stack_a, new);
			}
			info->j++;
		}
		info->i++;
	}
	free(sorted_mass);
	return (stack_a);
}

void	push_swap(t_list **stack_a, t_list **stack_b, t_info *info)
{	
	if (info->ac == 2)
	{
		if ((*stack_a)->index == 2)
			sa(stack_a);
	}
	else if (info->ac == 3)
	{
		sort_3(stack_a, info);
	}
	else if (info->ac == 4)
	{
		sort_5_push_b(stack_a, stack_b, info->min);
		sort_3(stack_a, info);
		pa(stack_a, stack_b);
	}
	else if (info->ac == 5)
		sort_5(stack_a, stack_b, info);
	else
		big_sort(stack_a, stack_b, info);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	stack_b = NULL;
	info->ac = ac - 1;
	if (info->ac <= 1)
		errors("Error");
	dublucate(av);
	stack_a = init_all(ac, av, stack_a, info);
	if (is_sorted(stack_a))
	{
		push_swap(&stack_a, &stack_b, info);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	free(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:02:05 by amahi             #+#    #+#             */
/*   Updated: 2022/03/28 02:51:01 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	out(t_list *stack_a, t_list *stack_b, t_info *info)
{
	while(stack_a != NULL  || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			printf("stack a[%d] = %d", stack_a->index, stack_a->value);
			stack_a = stack_a->next;
		}
		else
			printf("\t");
		if (stack_b != NULL)
		{
			printf("\t\tstack b[%d] = %d \n", stack_b->index, stack_b->value);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
	}
	printf("min = %d\n", info->min);
	printf("med = %d\n", info->med);
	printf("max = %d\n\n", info->max);
}

t_list *init_all(int ac, char **av, t_list *stack_a, t_info *info)
{
	t_list		*new;
	int			*sorted_mass;
	int			i;
	int			j;

	dublucate(av);
	sorted_mass = sorted_massiv(av, ac, info);
	i = 1;
	stack_a = init_list(form_char_to_int(av[1]), i);
	while (i < ac)
	{
		j = 0;
		while (j < ac - 1)
		{
			if (form_char_to_int(av[i]) == sorted_mass[j])
			{
				new = init_list(form_char_to_int(av[i]), j + 1);
				add_elem_back(&stack_a, new);
			}
			j++;
		}
		i++;
	}
	return(stack_a->next);
}

void push_swap(t_list **stack_a, t_list **stack_b, t_info *info)
{	
	if (info->ac == 2)
	{
		if ((*stack_a)->index == 2)
			sa(stack_b);
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
	{
		sort_5_push_b(stack_a, stack_b, info->max);
		sort_5_push_b(stack_a, stack_b, info->min);
		sort_3(stack_a, info);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else
		big_sort(stack_a, stack_b, info);
}

int main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_info		*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->ac = ac - 1;
	stack_a = init_all(ac, av, stack_a, info);
	push_swap(&stack_a, &stack_b, info);
	// printf("nos = %d\n\n", info->nos);
	// out(stack_a, stack_b, info);
}
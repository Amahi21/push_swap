#include "push_swap.h"

void	score(int i, int j, t_info *info)
{
	// printf("i = %d, j = %d\n", i, j);
	if (i + j < info->sum)
	{
		info->sum = i + j;
		info->flag = 1;
		info->ra = i;
		info->rb = j;
	}
	else if (i + info->len_b - j < info->sum)
	{
		info->sum = i + info->len_b - j;
		info->flag = 2;
		info->ra = i;
		info->rrb = info->len_b - j;
	}
	else if (info->len_a - i + j < info->sum)
	{
		info->sum = info->len_a - i + j;
		info->flag = 3;
		info->rra = info->len_a - i;
		info->rb = j;
	}
	else if (info->len_a - j + info->len_b - i < info->sum)
	{
		info->sum = info->len_a - j + info->len_b - i;
		info->flag = 4;
		info->rra = info->len_a - i;
		info->rrb = info->len_b - j;
	}
}

t_list	*helper(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*end;

		end = *stack_a;
		while (end->next)
			end = end->next;
		info->len_a = len_list(stack_a);
		info->len_b = len_list(stack_b);
	return (end);
}

void	final_sort(t_list **stack_a, t_list **stack_b, t_info *info)
{
	while (*stack_b)
	{
		
		if (info->flag == 1)
		{
			while (info->ra != 0)
			{
				ra(stack_a);
				info->ra--;
			}
			while(info->rb);
			{
				rb(stack_b);
				info->rb--;
			}
		}
		else if (info->flag == 2)
		{
			while (info->ra != 0)
			{
				ra(stack_a);
				info->ra--;
			}
			while (info->rrb != 0)
			{
				rrb(stack_b);
				info->rrb--;
			}
		}
		else if (info->flag == 3)
		{
			while (info->rra != 0)
			{
				rra(stack_a);
				info->rra--;
			}
			while (info->rb != 0)
			{
				rb(stack_b);
				info->rb--;
			}
		}
		else if (info->flag == 4)
		{
			while (info->rra != 0)
			{
				rra(stack_a);
				info->rra--;
			}
			while (info->rrb != 0)
			{
				rrb(stack_b);
				info->rrb--;
			}
		}
		pa(stack_a, stack_b);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, t_info *info)
{
	t_list	*tmpa;
	t_list	*tmpb;
	t_list	*end;
	int		i;
	int		j;

	put_3m(stack_a, stack_b, info);
	tmpa = *stack_a;
	i = 0;
	while (tmpa->next)
	{
		end = helper(stack_a, stack_b, info);
		j = 0;
		tmpb = *stack_b;
		while (tmpb->next)
		{
			if (tmpb->index > tmpa->index && tmpb->index < tmpa->next->index)
				score(i + 1, j, info);
			j++;
			tmpb = tmpb->next;	
		}
		i++;
		tmpa = tmpa->next;
	}
	printf("flag = %d\n", info->flag);
	printf("ra = %d\nrra = %d\nrb = %d\nrrb = %d\n", info->ra, info->rra, info->rb, info->rrb);

}
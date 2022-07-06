/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:18:35 by amahi             #+#    #+#             */
/*   Updated: 2022/07/05 20:33:00 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				error("Error");
			j++;
		}
		i++;
	}
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
			error("Error");
		while (av[j])
		{
			if (form_char_to_int(av[i]) == form_char_to_int(av[j]) && i != j)
				error("Error");
			j++;
		}
		i++;
	}
}

int	form_char_to_int(char *s)
{
	int		i;
	long	neg;
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
				error("Error");
		}
		else
			error("Error");
		i++;
	}
	return ((int)(tmp * neg));
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)str1;
	b = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (--n && a[i] == b[i] && a[i])
		i++;
	if (a[i] != b[i])
		return (a[i] - b[i]);
	return (0);
}

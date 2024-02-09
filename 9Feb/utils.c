/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:58:14 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/08 18:39:11 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		printf("a[i] este %i\n", a[i]);
		i++;
	}
	return (i);
}

int	check_is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		++i;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

int	ft_atoi(char *arg)
{
	int	i;
	int	nr;
	int	sign;

	i = 0;
	nr = 0;
	sign = 1;
	if (arg[0] == '-')
	{
		sign = -1;
		++i;
	}
	else if (arg[0] == '+')
		++i;
	while (arg[i] && (arg[i] >= '0' && arg[i] <= '9'))
	{
		nr = nr * 10 + (arg[i] - '0');
		i++;
	}
	return (sign * nr);
}

long	check_is_int(char *arg)
{
	int			i;
	long int	nr;
	int			sign;

	i = 0;
	nr = 0;
	sign = 1;
	if (arg[0] == '-')
	{
		sign = -1;
		++i;
	}
	else if (arg[0] == '+')
		++i;
	while (arg[i] && (arg[i] >= '0' && arg[i] <= '9'))
	{
		nr = nr * 10 + (arg[i] - '0');
		i++;
	}
	if (((sign * nr) < -2147483648) || (sign * nr) > 2147483647)
		return (0);
	return (1);
}

int	check_sorted(int *arr, int len_a) // if not sorted print 0
{
	int	i;
	int	sorted;

	i = 1;
	sorted = 1; // if sorted print 1
	while (i < len_a && len_a > 1)
	{
		if (arr[i - 1] > arr[i])
			sorted = 0;
		i++;
	}
	return (sorted);
}

void	ft_free(char **char_a, int *a, int *b)
{
	free(a);
	free(b);
	free(char_a);
	printf("ERROR from FT_FREE function\n");
	return ;
}

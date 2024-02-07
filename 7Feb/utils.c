/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:58:14 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/01 16:58:17 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen (char *a)
{
	int i = 0;

	while (a[i])
	{
		printf("a[i] este %s\n", a[i]);
		i++;
	}
	return (i);
}

int	check_is_number(char *arg)
{
	int i;

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
	int i = 0;
	int nr = 0;
	int sign = 1;
	if (arg[0] == '-')
	{
		sign = -1;
		++i;
	} else if (arg[0] == '+')
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
	int i = 0;
	long int nr = 0;
	int sign = 1;
	if (arg[0] == '-')
	{
		sign = -1;
		++i;
	} else if (arg[0] == '+')
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

int check_sorted(int *arr, int len_a) // if not sorted print 0
{
	int i;

	i = 1;
	int sorted;
	sorted = 1; // if sorted print 1

	while (i < len_a && len_a > 1)
	{
		if (arr[i - 1] > arr[i])
			sorted = 0;
		i++;
	}
	return (sorted);
}

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
	while (arg[i] && arg[i] >= '0' && arg[i] <= '9')
	{
		nr = nr * 10 + (arg[i] - '0');
		i++;
	}	
	return (sign * nr);
}

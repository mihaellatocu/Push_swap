/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:49:10 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/16 13:50:51 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_array(int *a, int len)
{
	int	i;
	int	j;
	int	counter;
	int	*sorted_array;

	i = 0;
	sorted_array = malloc(sizeof(int) * len);
	while (i < len)
	{
		j = 0;
		counter = 0;
		while (j < len)
		{
			if (a[i] > a[j])
				++counter;
			j++;
		}
		sorted_array[counter] = a[i];
		i++;
	}
	return (sorted_array);
}

static int	ranking(int *sorted_array, int elem)
{
	int	ranking;

	ranking = 0;
	while (sorted_array[ranking])
	{
		if (sorted_array[ranking] == elem)
			return (ranking);
		ranking++;
	}
	return (0);
}

void	compare(int *a, int *b, int *len_a, int *len_b)
{
	int	*sorted_array;
	int	i;
	int	section[2];
	int	ctr;

	i = 0;
	sorted_array = sort_array(a, *len_a);
	section[0] = *len_a / 10;
	section[1] = section[0];
	while (*len_a > 0)
	{
		ctr = 0;
		while (ctr < section[0])
		{
			if (ranking(sorted_array, a[i]) < section[1])
			{
				push_b(a, b, &len_a, &len_b);
				ctr++;
			}
			else
				rotate_a(a, *len_a);
		}
		section[1] += section[0];
	}
	free(sorted_array);
}

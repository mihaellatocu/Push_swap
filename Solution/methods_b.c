/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:41:28 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/16 11:41:30 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(int *b, int len_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = b[0];
	while (i < len_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = temp;
	write (1, "rb\n", 3);
}

void	reverse_rb(int *b, int len_b)
{
	int	i;
	int	temp;

	i = len_b;
	temp = b[len_b - 1];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write(1, "rrb\n", 4);
}

int	maximum(int *b, int len_b)
{
	int	pozition;
	int	i;
	int	maxim;

	pozition = 0;
	maxim = -2147483648;
	i = 0;
	while (i < len_b)
	{
		if (b[i] > maxim)
		{
			maxim = b[i];
			pozition = i;
		}
		i++;
	}
	return (pozition);
}

void	sort_b(int *a, int *b, int *len_a, int *len_b)
{
	int	poz;

	while (*len_b > 0)
	{
		poz = maximum(b, *len_b);
		if (poz == 0)
			push_a(a, b, &len_a, &len_b);
		else if (poz > 0 && poz <= *len_b / 2)
			while (poz-- > 0)
				rotate_b (b, *len_b);
		else if (poz > 0 && poz > *len_b / 2)
			while (poz++ < *len_b)
				reverse_rb(b, *len_b);
	}
	if (*len_b == 2 && b[0] < b[1])
		rotate_b (b, *len_b);
}

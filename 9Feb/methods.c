/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:33:43 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/08 18:46:18 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(int *a, int *b, int **len_a, int **len_b) //(t_stack *stack)//int *a, int *b, *len_a, *len_b)
{
	int	i;

	i = (**len_b)++; // pointing to the len of b
	while (i > 0)
	{
		b[i] = b[i - 1];
		--i;
	}
	b[0] = a[0];
	i = 0;
	while (i < **len_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(**len_a)--;
	write(1, "pb\n", 3);
}

void	push_a(int *a, int *b, int **len_a, int **len_b)
{
	int	i;

	++(**len_a); //len_a=4     i = 4 len_a = 5
	i = **len_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < **len_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(**len_b)--;
	write (1, "pa\n", 3);
}

void	rotate_a(int *a, int len_a) // ra first elem becomes the last one
{
	int	i;
	int	temp;

	i = 0;
	temp = a[0];
	while (i < len_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	write (1, "ra\n", 3);
}

void	reverse_ra(int *a, int len_a) // rra The last elem becomes the first one
{
	int	i;
	int	temp;

	i = len_a;
	temp = a[len_a - 1];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	write(1, "rra\n", 4);
}

int	minim(int *a, int len_a)
{
	int	pozition;
	int	i;
	int	minim;

	pozition = 0;
	minim = 2147483647;
	i = 0;
	while (i < len_a)
	{
		if (a[i] < minim)
		{
			minim = a[i];
			pozition = i;
		}
		i++;
	}
	return (pozition);
}

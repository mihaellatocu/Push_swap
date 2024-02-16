/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:19 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/08 19:03:48 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_include(int *stack, int stack_len, int number)
{
	int	index;

	index = 0;
	while (index < stack_len)
	{
		if (stack[index] == number)
			return (write(1, "Error\n", 6), 1);
		++index;
	}
	return (0);
}

void	sort_a(int *a, int *b, int *len_a, int *len_b)
{
	int	poz;

	while (*len_a > 2)
	{
		poz = minim(a, *len_a);
		if (poz == 0)
			push_b(a, b, &len_a, &len_b);
		else if (poz > 0 && poz <= *len_a / 2)
			while (poz-- > 0)
				rotate_a (a, *len_a);
		else if (poz > 0 && poz > *len_a / 2)
			while (poz++ < *len_a)
				reverse_ra(a, *len_a);
	}
	if (*len_a == 2 && a[0] > a[1])
		rotate_a (a, *len_a);
	while (*len_b > 0)
		push_a (a, b, &len_a, &len_b);
}

static char	**initialise(int argc, char *argv[], t_stack *stack)
{
	int		j;
	char	**array_char;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	j = 1;
	array_char = malloc(sizeof(char *) * (argc));
	stack->a = malloc(sizeof(int) * (argc - 1));
	stack->b = malloc(sizeof(int) * (argc -1));
	stack->len_a = argc - 1;
	stack->len_b = 0;
	while (argc > 1 && argv[j])
	{
		array_char[j - 1] = argv[j];
		++j;
	}
	return (array_char);
}

int	main(int argc, char *argv[])
{
	int		j;
	char	**array_char;
	t_stack	stack;

	array_char = initialise(argc, argv, &stack);
	j = -1;
	while (++j < argc - 1)
	{
		if (!check_is_number(array_char[j]) || !check_is_int(array_char[j]))
			return (ft_free(array_char, stack.a, stack.b), 1);
		stack.a[j] = ft_atoi(array_char[j]);
		if (stack_include(stack.a, j, stack.a[j]))
			return (ft_free(array_char, stack.a, stack.b), 1);
	}
	if (!check_sorted(stack.a, stack.len_a))
	{
		if (stack.len_a < 50)
			sort_a(stack.a, stack.b, &stack.len_a, &stack.len_b);
		else
		{
			compare(stack.a, stack.b, &stack.len_a, &stack.len_b);
			sort_b(stack.a, stack.b, &stack.len_a, &stack.len_b);
		}
	}
	return (ft_free(array_char, stack.a, stack.b), 0);
}

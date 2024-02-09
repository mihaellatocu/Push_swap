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
			return (1);
		++index;
	}
	return (0);
}

void	swap(int a, int b)
{
	int	temp;

	temp = a;
	a = b;
	b = temp;
	//printf("swap\n");
}

void	sort_a(int *a, int *b, int *len_a, int *len_b, char *array_char)
{
	int	poz;

	if (a[0] > a[1] && *len_a == 2)
		swap(a[0], a[1]);
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
	//free(array_char);
	//free(b);
	//free(a); //to enable when not printed the arrays
}

int	main(int argc, char *argv[])
{
	int		j;
	char	**array_char;
	t_stack	stack;

	j = 1;
	if (argc <= 1)
		return (0);// what means 0 or 1?
	array_char = malloc(sizeof(char *) * (argc - 1));
	stack.a = malloc(sizeof(int) * (argc - 1));
	stack.b = malloc(sizeof(int) * (argc -1));
	stack.len_a = argc - 1;
	stack.len_b = 0;
	while (argc > 1 && argv[j])
	{
		array_char[j - 1] = argv[j];
		++j;
	}
	j = 0;
	while (j < argc - 1)//(argc && argv[j])
	{
		if (!check_is_number(array_char[j]) || !check_is_int(array_char[j]))
			return (ft_free(array_char, stack.a, stack.b), 1);
		int	number = ft_atoi(array_char[j]);
		if (stack_include(stack.a, j, number))
			return (ft_free(array_char, stack.a, stack.b), 1);
		stack.a[j] = number;
		j++;
	}
	if (!check_sorted(stack.a, stack.len_a))
	{
		sort_a(stack.a, stack.b, &stack.len_a, &stack.len_b, *array_char);
		//free (array_char);
	}
	int i = -1;
	printf("Stack_len a %d\n", stack.len_a);
	while (i++ < stack.len_a - 1) // to be removed later
	{
		printf("%d ", stack.a[i]);
		
	}
	//free(stack.a);
	return (0);
}

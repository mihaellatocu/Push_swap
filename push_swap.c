/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:55:19 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/03 16:40:18 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *arg)
{
	int i = 1;
	
	while (arg[i])
	{
		if (arg[i] == arg[i - 1])
			return 0;
		i++;
	}
	return 1;
}


int stack_include(int *stack, int stack_len, int number) {
	int index = 0;

	while (index < stack_len)
	{
		if (stack[index] == number)
			return 1;
		++index;
	}
	return 0;
}


// int	check(char *arg)
// {
//     int i = 0;
//     char *fv;

//     while (arg[i])
//     {
//         ++fv[arg[i]];
//         ++i;
//     }
//     int j = 0;
//     while (fv[j])
//     {
//         printf("%d\n", fv[j]);
//         ++j;
//         if (fv[j] == 2)
//             return (0);
//     }
// 	return (1);

// }

void	sort_a(int *a, int *b, int *len_a, int *len_b)
{
	while (*len_a > 2)
	{
		int poz;

		poz = minim(a, *len_a);
		if (poz == 0)
			push_b(a, b, &len_a, &len_b);
		else if (poz > 0 && poz <= *len_a / 2)
			 while (poz-- > 0 )
				rotate_a(a, *len_a);
		else if (poz > 0 && poz > *len_a / 2)
			while (poz++ < *len_a)
				reverse_ra(a, *len_a);
	}
	if (*len_a == 2 && a[0] > a[1])
		rotate_a(a, *len_a);
	while (*len_b > 0)
		push_a(a, b, &len_a, &len_b);
}


int	main(int argc, char *argv[])
{
	int j;
	int i;
	char **array_char;
	t_stack	stack;

	j = 1;
	//i = 0;
	(void)i;
	if (argc <= 1)
		return (0);
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
		if (!check_is_number(array_char[j]))
		{
			free(array_char);
			free(stack.a);
			printf("ERROR");
			return (1);
		}

		int number = ft_atoi(array_char[j]);
		if (stack_include(stack.a, j, number)) {
			printf("ERROR -----------------------\n");
			return 1;
		}
		stack.a[j] = number;
		j++;
	}


	sort_a(stack.a, stack.b, &stack.len_a, &stack.len_b);

	if (check_duplicates(stack.a) == 0)
		printf("There are duplicates in the array!");
	while (i < stack.len_a)
	{
		printf("%d ", stack.a[i]);
		++i;
	}
	return (0);
}

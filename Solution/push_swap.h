/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:37:08 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/08 18:41:05 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}				t_stack;

int		check_is_number(char *arg);
int		ft_atoi(char *arg);
void	push_b(int *a, int *b, int **len_a, int **len_b);
void	push_a(int *a, int *b, int **len_a, int **len_b);
void	rotate_a(int *a, int len_a);
void	reverse_ra(int *a, int len_a);
int		minim(int *a, int len_a);
void	sort_a(int *a, int *b, int *len_a, int *len_b);
int		check_sorted(int *arr, int len_a);
long	check_is_int(char *arg);
void	ft_free(char **char_a, int *a, int *b);

void	rotate_b(int *b, int len_b);
void	reverse_rb(int *b, int len_b);
int		maximum(int *b, int len_b);
void	sort_b(int *a, int *b, int *len_a, int *len_b);
int		*sort_array(int *a, int j);
void	compare(int *a, int *b, int *len_a, int *len_b);

#endif
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

int		ft_strlen(char *a);
int		check_is_number(char *arg);
int		ft_atoi(char *arg);
void	push_b(int *a, int *b, int **len_a, int **len_b);
void	push_a(int *a, int *b, int **len_a, int **len_b);
void	rotate_a(int *a, int len_a);
void	reverse_ra(int *a, int len_a);
int		minim(int *a, int len_a);
void	sort_a(int *a, int *b, int *len_a, int *len_b, char *array_char);
int		check_sorted(int *arr, int len_a);
long	check_is_int(char *arg);
void	ft_free(char **char_a, int *a, int *b);

//from ft_printf
int		print_char(int c);
int		print_str(char *str);
int		print_digit(long n, int base, int upper);
int		ft_len(unsigned long int x);
int		ft_print_pointer(unsigned long int x);
int		print_format(char specifier, va_list ap);
//int	ft_printf(const char *format, ...);



#endif

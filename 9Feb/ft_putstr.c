/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:33:11 by mtocu             #+#    #+#             */
/*   Updated: 2024/02/08 18:39:38 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_putstr(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		printf("%s", arg[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:10:48 by lperis            #+#    #+#             */
/*   Updated: 2024/10/29 14:56:16 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	minus;
	int	i;
	

	i = 0;
	res = 0;
	minus = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > (LLONG_MAX - (nptr[i] - '0') / 10))
		{
			if (minus == 1)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * minus);
}

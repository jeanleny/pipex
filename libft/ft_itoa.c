/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:03:45 by lperis            #+#    #+#             */
/*   Updated: 2024/10/31 09:54:38 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 

static int	count_numbers(int n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	if (n == 0)
		length++;
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = count_numbers(n);
	str = ft_calloc(length + 1, 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (n == 0)
		str[length - 1] = (n % 10) + 48;
	while (n > 0)
	{
		str[length - 1] = (n % 10) + 48;
		n = n / 10;
		length--;
	}
	return (str);
}

int main(void)
{
	char *str = ft_itoa(-214);
	printf("%s", str);
	free(str);
}

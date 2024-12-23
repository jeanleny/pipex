/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_pfd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:43:06 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 12:57:43 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_pfd.h"

int	ft_putnbr_hexa_pfd(int fd, unsigned int nb, int b)
{
	char	*base;
	int		count;

	count = 0;
	base = NULL;
	if (b == 'x')
		base = "0123456789abcdef";
	else if (b == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putnbr_hexa_pfd(fd, nb / 16, b);
	count += ft_putchar_pfd(fd, base[nb % 16]);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:41:00 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 12:57:54 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_pfd.h"

int	ft_putnbr_pfd(int fd, int nb)
{
	int	a;
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count = write(fd, "-2147483648", 11);
		return (count);
	}
	else if (nb < 0)
	{
		count += ft_putchar_pfd(fd, '-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr_pfd(fd, nb / 10);
	}
	a = (nb % 10 + 48);
	count += ft_putchar_pfd(fd, a);
	return (count);
}

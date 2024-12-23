/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem_pfd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:08:10 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 15:43:59 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_pfd.h"

unsigned int	ft_putnbr_mem_pfd(int fd, size_t nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putnbr_mem_pfd(fd, nb / 16);
	count += ft_putchar_pfd(fd, base[nb % 16]);
	return (count);
}

unsigned int	ft_print_mem_pfd(int fd, size_t nb)
{
	int	count;

	count = 0;
	if (!nb)
	{
		ft_putstr_pfd(fd, "(nil)");
		return (5);
	}
	else
	{
		count += ft_putstr_pfd(fd, "0x");
		count += ft_putnbr_mem_pfd(fd, nb);
	}
	return (count);
}

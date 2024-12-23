/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign_pfd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:47:22 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 12:58:04 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_pfd.h"

unsigned int	ft_putnbr_unsign_pfd(int fd, unsigned int nb)
{
	int	a;
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_unsign_pfd(fd, nb / 10);
	a = (nb % 10 + 48);
	count += ft_putchar_pfd(fd, a);
	return (count);
}

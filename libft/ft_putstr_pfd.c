/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:39:13 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 12:58:12 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_pfd.h"

int	ft_putstr_pfd(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(fd, str++, 1);
		i++;
	}
	return (i);
}

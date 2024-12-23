/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pfd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:35:03 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 15:41:46 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_pfd.h"

int	check_params_pfd(int fd, const char format, va_list param, int count)
{
	if (format == 's')
		count += ft_putstr_pfd(fd, va_arg(param, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_pfd(fd, va_arg(param, int));
	else if (format == 'x' || format == 'X')
		count += ft_putnbr_hexa_pfd(fd, va_arg(param, int), format);
	else if (format == 'u')
		count += ft_putnbr_unsign_pfd(fd, va_arg(param, unsigned int));
	else if (format == 'p')
		count += ft_print_mem_pfd(fd, (size_t)va_arg(param, void *));
	else if (format == 'c')
		count += ft_putchar_pfd(fd, va_arg(param, int));
	else if (format == '%')
		count += ft_putchar_pfd(fd, '%');
	else
	{
		write(fd, "Undefined behaviour", 19);
		return (-1);
	}
	return (count);
}

int	ft_printf_pfd(int fd, const char *format, ...)
{
	va_list	param;
	int		count;

	va_start(param, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format && count != -1)
	{
		if (*format == '%')
		{
			format++;
			count = check_params_pfd(fd, *format, param, count);
		}
		else if (*format != '%')
			count += ft_putchar_pfd(fd, *format);
		format++;
	}
	va_end(param);
	return (count);
}

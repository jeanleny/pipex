/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pfd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:59:00 by lperis            #+#    #+#             */
/*   Updated: 2024/12/23 15:39:38 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PFD_H

# define FT_PRINTF_PFD_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_putstr_pfd(int fd, char *str);
unsigned int	ft_putnbr_unsign_pfd(int fd, unsigned int nb);
unsigned int	ft_print_mem_pfd(int fd, size_t nb);
int				ft_putnbr_hexa_pfd(int fd, unsigned int nb, int b);
int				ft_putnbr_pfd(int fd, int nb);
int				ft_putchar_pfd(int fd, int c);

#endif

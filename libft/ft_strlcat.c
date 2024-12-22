/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:16:45 by lperis            #+#    #+#             */
/*   Updated: 2024/10/24 15:36:11 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;

	if (size == 0 && dst == NULL)
		return (ft_strlen(src));
	i = 0;
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if ((dst_length) < size)
	{
		while (src[i] != '\0' && (dst_length + i) < size - 1)
		{
			dst[dst_length + i] = src[i];
			i++;
		}
		dst[dst_length + i] = '\0';
		return (dst_length + src_length);
	}
	else
		return (src_length + size);
}

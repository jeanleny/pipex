/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:55 by lperis            #+#    #+#             */
/*   Updated: 2024/10/24 15:43:19 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		little_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (big == NULL && len == 0)
		return (NULL);
	if (little_len == 0)
		return ((char *)big);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	i = 0;
	while ((i + little_len) <= len)
	{
		if (ft_memcmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

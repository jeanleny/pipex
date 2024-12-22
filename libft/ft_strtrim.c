/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:52:30 by lperis            #+#    #+#             */
/*   Updated: 2024/10/24 15:45:12 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	i;
	unsigned int	length;
	char			*str;

	i = 0;
	if (set == NULL || s1 == NULL)
		return (NULL);
	length = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (length != 0 && ft_strchr(set, s1[length]) != NULL)
		length--;
	str = ft_substr(s1, i, length - i + 1);
	return (str);
}

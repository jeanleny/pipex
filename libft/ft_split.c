/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:58:25 by lperis            #+#    #+#             */
/*   Updated: 2024/10/25 10:21:46 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static int	ft_strnlen(char *s, char c)
{
	int	length;

	length = 0;
	while ((*s != '\0') && (*s != c))
	{
		length++;
		s++;
	}
	return (length);
}

static char	**ft_wordalloc(char *s, char c, char **tab)
{
	int	i;
	int	size;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			size = ft_strnlen(s, c);
			tab[i] = ft_calloc(size + 1, (sizeof(char)));
			if (tab[i] == NULL)
			{
				ft_free(tab, i - 1);
				return (NULL);
			}
			ft_strlcpy(tab[i], s, size + 1);
			i++;
			s += size;
		}
	}
	tab[i] = NULL;
	return (tab);
}

static int	ft_countwords(char *s, char sep)
{
	int	count;
	int	inword;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s == sep)
			inword = 0;
		else if (*s != sep && inword == 0)
		{
			inword = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**words_tab;

	if (!s)
		return (NULL);
	words_tab = ft_calloc(ft_countwords((char *)s, c) + 1, (sizeof (char *)));
	if (words_tab == NULL)
		return (NULL);
	words_tab = ft_wordalloc((char *)s, c, words_tab);
	return (words_tab);
}

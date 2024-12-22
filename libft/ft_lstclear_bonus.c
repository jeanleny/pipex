/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:16:37 by lperis            #+#    #+#             */
/*   Updated: 2024/10/23 15:28:12 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*fromdel;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		fromdel = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = fromdel;
	}
}

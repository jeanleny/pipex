/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:02:53 by lperis            #+#    #+#             */
/*   Updated: 2024/10/23 15:24:24 by lperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void *))
{
	t_list	*new_l;
	t_list	*new_elem;
	void	*func_content;

	new_l = 0;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		func_content = f(lst->content);
		new_elem = ft_lstnew(func_content);
		if (!new_elem)
		{
			del(func_content);
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_elem);
		lst = lst->next;
	}
	return (new_l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:35:28 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/22 19:35:28 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*s1;
	t_list	*s2;

	if (!lst)
		return (NULL);
	s2 = f(lst);
	s1 = s2;
	while (lst->next)
	{
		lst = lst->next;
		if (!(s2->next = f(lst)))
		{
			free(s2->next);
			return (NULL);
		}
		s2 = s2->next;
	}
	return (s1);
}

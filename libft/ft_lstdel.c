/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:48:09 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:10 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *list;
	t_list *save;

	list = *alst;
	if (alst && del)
	{
		while (list != NULL)
		{
			save = list->next;
			del(list, list->content_size);
			list = save;
		}
		*alst = NULL;
	}
}

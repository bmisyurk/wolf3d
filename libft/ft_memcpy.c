/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:42:14 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/10/25 19:42:36 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	char		*q;
	const char	*w;

	q = destptr;
	w = srcptr;
	while (num > 0)
	{
		*q++ = *w++;
		num--;
	}
	return (destptr);
}

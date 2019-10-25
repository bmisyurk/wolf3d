/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:19:34 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/10/28 19:20:33 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destptr, const void *srcptr, int c, size_t n)
{
	unsigned char		*q;
	unsigned char		*w;

	q = (unsigned char*)destptr;
	w = (unsigned char*)srcptr;
	while (n > 0 && *w != (unsigned char)c)
	{
		n--;
		*q++ = *w++;
	}
	destptr = q;
	if (n > 0)
	{
		*q++ = *w++;
		return ((void*)q);
	}
	else
		return (NULL);
}

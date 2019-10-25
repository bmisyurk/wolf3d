/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:36:24 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/08 18:36:33 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*dnew;
	const char	*snew;
	size_t		nnew;
	size_t		dlen;

	dnew = dest;
	snew = src;
	nnew = size;
	while (nnew-- != 0 && *dnew != '\0')
		dnew++;
	dlen = dnew - dest;
	nnew = size - dlen;
	if (nnew == 0)
		return (dlen + ft_strlen(snew));
	while (*snew != '\0')
	{
		if (nnew != 1)
		{
			*dnew++ = *snew;
			nnew--;
		}
		snew++;
	}
	*dnew = '\0';
	return (dlen + (snew - src));
}

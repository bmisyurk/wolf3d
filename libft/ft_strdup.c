/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:13:36 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/09/24 16:13:48 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*m;
	char	*zet;
	int		k;

	k = 0;
	while (src[k++] != '\0')
		;
	if (!(zet = (char*)malloc(k)))
		return (NULL);
	m = zet;
	while ((*m++ = *src++) != '\0')
		;
	return (zet);
}

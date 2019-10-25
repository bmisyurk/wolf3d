/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:29:05 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/11 16:29:06 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	const char *s1;
	const char *s2;

	if (*sub == '\0')
		return ((char*)str);
	while (*str != '\0')
	{
		s1 = str;
		s2 = sub;
		while (*s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char*)str);
		str++;
	}
	return (NULL);
}

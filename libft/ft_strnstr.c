/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:29:31 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/09 22:29:33 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		l;
	const char	*s1;

	if (*sub == '\0')
		return ((char*)str);
	i = 0;
	j = ft_strlen(sub);
	while (str[i] != '\0' && (i + j) <= len)
	{
		l = 0;
		s1 = &str[i];
		while (s1[l] == sub[l] && i < len)
		{
			if (sub[l + 1] == '\0')
				return ((char*)str + i);
			l++;
		}
		i++;
	}
	return (NULL);
}

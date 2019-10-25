/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:26:15 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/14 21:26:16 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

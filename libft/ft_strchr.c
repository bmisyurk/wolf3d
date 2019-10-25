/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 23:02:05 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/09/22 23:06:17 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	int		i;
	char	*str;

	i = 0;
	if (s)
	{
		str = (char*)s;
		while (str[i] != '\0' && str[i] != ch)
			i++;
		if (str[i] == ch)
			return (&str[i]);
		return (NULL);
	}
	return (NULL);
}

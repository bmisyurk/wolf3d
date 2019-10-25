/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:36:17 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/16 20:36:18 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	n;

	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str == NULL)
			return (NULL);
		n = 0;
		while (s[n] != '\0')
		{
			str[n] = f(n, s[n]);
			n++;
		}
		return (str);
	}
	else
		return (NULL);
}

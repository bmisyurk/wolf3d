/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:07:15 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/14 20:07:15 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[n] = f(s[n]);
			n++;
		}
		return (str);
	}
	else
		return (NULL);
}

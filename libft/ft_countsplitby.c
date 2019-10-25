/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countsplitby.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 22:52:59 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/22 22:52:59 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countsplitby(char *str, char c)
{
	size_t	num;
	size_t	i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			if (str[i] == c || str[i] == '\0')
			{
				num++;
			}
		}
	}
	return (num);
}

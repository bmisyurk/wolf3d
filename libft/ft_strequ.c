/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnqu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:08:41 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/14 21:08:42 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	res;

	if (s1 && s2)
	{
		res = ft_strcmp(s1, s2);
		if (res == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

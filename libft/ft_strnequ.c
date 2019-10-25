/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:17:03 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/14 21:17:04 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	res;

	if (s1 && s2)
	{
		res = ft_strncmp(s1, s2, n);
		if (res == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

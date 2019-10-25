/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:23:53 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/16 21:23:53 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int col;

	col = 0;
	if (n < 0)
		col++;
	if (n == 0)
		col++;
	while (n != 0)
	{
		n /= 10;
		col++;
	}
	return (col);
}

char		*ft_itoa(int n)
{
	unsigned int	x;
	int				i;
	int				size;
	char			*buf;

	i = 0;
	size = ft_len(n);
	buf = ft_strnew(size);
	if (buf == NULL)
		return (NULL);
	buf[size--] = '\0';
	x = n;
	if (n < 0)
	{
		x = -n;
		buf[i++] = '-';
	}
	if (x == 0)
		buf[i++] = '0';
	while (x != 0)
	{
		buf[size--] = x % 10 + '0';
		x /= 10;
	}
	return (buf);
}

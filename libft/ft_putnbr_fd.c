/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:39:44 by bmisyurk          #+#    #+#             */
/*   Updated: 2017/11/15 17:39:45 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	f;

	f = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		f = f * (-1);
	}
	if (f > 9)
	{
		ft_putnbr_fd(f / 10, fd);
	}
	ft_putchar_fd(48 + f % 10, fd);
}

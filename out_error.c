/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:05:18 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/09/05 16:05:21 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	out_error(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr("\n");
	exit(1);
}

int		exit_cl(void *click)
{
	click = NULL;
	exit(1);
	return (0);
}

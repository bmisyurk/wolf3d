/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:46:49 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/01 21:46:52 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vect		new_vect(double a, double b)
{
	t_vect v;

	v.x = a;
	v.y = b;
	return (v);
}

t_vect2i	new_vect2i(int a, int b)
{
	t_vect2i v;

	v.x = a;
	v.y = b;
	return (v);
}

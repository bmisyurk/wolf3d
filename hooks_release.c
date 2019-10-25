/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 00:20:13 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/31 00:20:14 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_on(int key, t_global *m)
{
	(key == ESC) ? (exit(0)) : 0;
	(key == 126) ? (m->up_down.x = 1) : 0;
	(key == 125) ? (m->up_down.y = 1) : 0;
	(key == 123) ? (m->left_right.x = 1) : 0;
	(key == 124) ? (m->left_right.y = 1) : 0;
	(key == 256 || key == 259) ? (m->shift = 1) : 0;
	if (key == 15)
	{
		m->posit_pl.x = m->old_player_pos.x;
		m->posit_pl.y = m->old_player_pos.y;
	}
	(key == 49) ? (m->txr = !m->txr) : 0;
	return (0);
}

int			key_off(int key, t_global *m)
{
	(key == 126) ? (m->up_down.x = 0) : 0;
	(key == 125) ? (m->up_down.y = 0) : 0;
	(key == 123) ? (m->left_right.x = 0) : 0;
	(key == 124) ? (m->left_right.y = 0) : 0;
	if (key == 256 || key == 259)
		m->shift = 0;
	return (0);
}

t_vect		rotate(t_vect v, double ang)
{
	double temp;
	double cos_teta;
	double sin_teta;

	temp = v.x;
	cos_teta = cos(ang);
	sin_teta = sin(ang);
	v.x = v.x * cos_teta - v.y * sin_teta;
	v.y = temp * sin_teta + v.y * cos_teta;
	return (v);
}

void		hook_t_l(t_global *m)
{
	m->cam_pl = rotate(m->cam_pl, -m->s_rot);
	m->cam_vector = rotate(m->cam_vector, -m->s_rot);
}

void		hook_t_r(t_global *m)
{
	m->cam_pl = rotate(m->cam_pl, m->s_rot);
	m->cam_vector = rotate(m->cam_vector, m->s_rot);
}

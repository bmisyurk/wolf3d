/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:46:18 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/01 21:46:20 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		cycle_hooks(t_global *m)
{
	if (m->up_down.x)
		move_forward(m);
	if (m->up_down.y)
		move_backwards(m);
	if (m->left_right.x)
		hook_t_l(m);
	if (m->left_right.y)
		hook_t_r(m);
	m->ry_struct.x = 0;
	m->ry_struct.y = 0;
	m->ry_struct.d = 0;
	raycasting(m);
	mlx_create(m);
	return (0);
}

int		is_movable(double x, double y, t_global *m)
{
	if (x > m->max_map_y - 1 || y > m->max_map_x - 1 || x < 1 || y < 1)
		return (0);
	if (m->map[(int)x][(int)y] == 0)
		return (1);
	return (0);
}

void	move_fast(t_global *m)
{
	int x;
	int y;
	int d;
	int k;

	x = m->posit_pl.x + m->cam_pl.x *
	m->s_move + 0.33 * m->cam_pl.x;
	y = m->posit_pl.y;
	d = m->posit_pl.x;
	k = m->posit_pl.y +
	m->cam_pl.y * m->s_move + 0.33 * m->cam_pl.y;
	if (is_movable(x, y, m))
		m->posit_pl.x += m->cam_pl.x * m->s_move;
	if (is_movable(d, k, m))
		m->posit_pl.y += m->cam_pl.y * m->s_move;
}

void	move_forward(t_global *m)
{
	int x;
	int k;

	x = m->posit_pl.x + m->cam_pl.x *
		m->s_shift + 0.33 * m->cam_pl.x;
	k = m->posit_pl.y +
		m->cam_pl.y * m->s_shift + 0.33 * m->cam_pl.y;
	if (m->shift)
	{
		if (is_movable(x, (int)m->posit_pl.y, m))
			m->posit_pl.x += m->cam_pl.x * m->s_shift;
		if (is_movable((int)m->posit_pl.x, k, m))
			m->posit_pl.y += m->cam_pl.y * m->s_shift;
	}
	else
		move_fast(m);
}

void	move_backwards(t_global *m)
{
	int x;
	int y;
	int d;
	int k;

	x = m->posit_pl.x - m->cam_pl.x *
	m->s_move - 0.33 * m->cam_pl.x;
	y = m->posit_pl.y;
	d = m->posit_pl.x;
	k = m->posit_pl.y -
	m->cam_pl.y * m->s_move - 0.33 * m->cam_pl.y;
	if (is_movable(x, y, m))
		m->posit_pl.x -= m->cam_pl.x * m->s_move;
	if (is_movable(d, k, m))
		m->posit_pl.y -= m->cam_pl.y * m->s_move;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_for_recast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:19:07 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/02 01:19:11 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_dist(t_global *m)
{
	while (!m->ry_struct.hit)
	{
		if (m->ry_struct.side.x < m->ry_struct.side.y)
		{
			m->ry_struct.side.x += m->ry_struct.delta.x;
			m->ry_struct.map.x += m->ry_struct.step_x;
			m->ry_struct.hit_side = 0;
		}
		else
		{
			m->ry_struct.side.y += m->ry_struct.delta.y;
			m->ry_struct.map.y += m->ry_struct.step_y;
			m->ry_struct.hit_side = 1;
		}
		if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] > 0)
			m->ry_struct.hit = 1;
	}
	init_dist2(m);
}

void	init_dist2(t_global *m)
{
	if (!m->ry_struct.hit_side)
		m->ry_struct.pwd = (m->ry_struct.map.x - m->ry_struct.pos.x +
			(1 - m->ry_struct.step_x) / 2) / m->ry_struct.dir.x;
	else
		m->ry_struct.pwd = (m->ry_struct.map.y - m->ry_struct.pos.y +
			(1 - m->ry_struct.step_y) / 2) / m->ry_struct.dir.y;
}

void	init_step(t_global *m)
{
	if (m->ry_struct.dir.y < 0)
	{
		m->ry_struct.step_y = -1;
		m->ry_struct.side.y = (m->ry_struct.pos.y -
		(int)m->ry_struct.pos.y) * m->ry_struct.delta.y;
	}
	else
	{
		m->ry_struct.step_y = 1;
		m->ry_struct.side.y = ((int)m->ry_struct.pos.y + 1.0 -
		m->ry_struct.pos.y) * m->ry_struct.delta.y;
	}
	init_step2(m);
}

void	init_step2(t_global *m)
{
	if (m->ry_struct.dir.x < 0)
	{
		m->ry_struct.step_x = -1;
		m->ry_struct.side.x = (m->ry_struct.pos.x -
		(int)m->ry_struct.pos.x) * m->ry_struct.delta.x;
	}
	else
	{
		m->ry_struct.step_x = 1;
		m->ry_struct.side.x = ((int)m->ry_struct.pos.x + 1.0 -
		m->ry_struct.pos.x) * m->ry_struct.delta.x;
	}
	init_dist(m);
}

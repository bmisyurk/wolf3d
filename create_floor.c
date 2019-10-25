/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:09:15 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/02 01:09:17 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	floor_render_2(t_global *m)
{
	double		dist;
	double		w;
	double		fx;
	double		fy;

	m->ry_struct.wall_dst = m->ry_struct.pwd;
	m->ry_struct.player_dst = 0.0;
	m->ry_struct.y = m->ry_struct.end + 1;
	(m->ry_struct.end < 0) ? (m->ry_struct.end = H) : 0;
	while (m->ry_struct.y < H)
	{
		dist = H / (2.0 * m->ry_struct.y - H);
		w = (dist - m->ry_struct.player_dst) /
		(m->ry_struct.wall_dst - m->ry_struct.player_dst);
		fx = w * m->ry_struct.floorxwall + (1.0 - w) * m->ry_struct.pos.x;
		fy = w * m->ry_struct.floorywall + (1.0 - w) * m->ry_struct.pos.y;
		m->ry_struct.floor_texx = (int)(fx *
			m->texture->width) % m->texture->width;
		m->ry_struct.floor_texy = (int)(fy *
			m->texture->height) % m->texture->height;
		add_floor(m);
		ceiling(m);
		m->ry_struct.y++;
	}
}

void	floor_render(t_global *m)
{
	if (!m->ry_struct.hit_side && m->ry_struct.dir.x > 0)
	{
		m->ry_struct.floorxwall = m->ry_struct.map.x;
		m->ry_struct.floorywall = m->ry_struct.map.y + m->ry_struct.wall_x;
	}
	else if (!m->ry_struct.hit_side && m->ry_struct.dir.x < 0)
	{
		m->ry_struct.floorxwall = m->ry_struct.map.x + 1.0;
		m->ry_struct.floorywall = m->ry_struct.map.y + m->ry_struct.wall_x;
	}
	else if (m->ry_struct.hit_side == 1 && m->ry_struct.dir.y > 0)
	{
		m->ry_struct.floorxwall = m->ry_struct.map.x + m->ry_struct.wall_x;
		m->ry_struct.floorywall = m->ry_struct.map.y;
	}
	else
	{
		m->ry_struct.floorxwall = m->ry_struct.map.x + m->ry_struct.wall_x;
		m->ry_struct.floorywall = m->ry_struct.map.y + 1.0;
	}
	floor_render_2(m);
}

void	add_floor(t_global *m)
{
	m->data[4 * (W * m->ry_struct.y + m->ry_struct.x) + 1] = m->texture
	[7].img_ptr[(4 * (m->texture->width * m->ry_struct.floor_texy +
		m->ry_struct.floor_texx)) + 1] >> 1 & 555555;
	m->data[4 * (W * m->ry_struct.y + m->ry_struct.x) + 2] = m->texture
	[7].img_ptr[(4 * (m->texture->width * m->ry_struct.floor_texy +
		m->ry_struct.floor_texx)) + 2] >> 1 & 555555;
	m->data[4 * (W * m->ry_struct.y + m->ry_struct.x)] = m->texture
	[7].img_ptr[(4 * (m->texture->width * m->ry_struct.floor_texy +
		m->ry_struct.floor_texx))] >> 1 & 555555;
}

void	ceiling(t_global *m)
{
	m->data[4 * (W * (H - m->ry_struct.y) + m->ry_struct.x)] = m->texture
	[8].img_ptr[(4 * (m->texture->width * m->ry_struct.floor_texy +
		m->ry_struct.floor_texx))];
	m->data[4 * (W * (H - m->ry_struct.y) + m->ry_struct.x) + 1] = m->texture
	[8].img_ptr[(4 * (m->texture->width * m->ry_struct.floor_texy +
		m->ry_struct.floor_texx)) + 1];
	m->data[4 * (W * (H - m->ry_struct.y) + m->ry_struct.x) + 2] = m->texture
	[8].img_ptr[(4 * (m->texture->width * m->ry_struct.floor_texy +
		m->ry_struct.floor_texx)) + 2];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:37:31 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/31 23:37:32 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_texture_to_img(t_global *m, int x, int y, int n)
{
	m->data[4 * (W * y + x) + 1] = m->texture[n].
	img_ptr[(4 * (m->texture[n].width *
		m->ry_struct.texture_y + m->ry_struct.texture_x)) + 1];
	m->data[4 * (W * y + x) + 2] = m->texture[n].
	img_ptr[(4 * (m->texture[n].width *
		m->ry_struct.texture_y + m->ry_struct.texture_x)) + 2];
	m->data[4 * (W * y + x)] = m->texture[n].
	img_ptr[(4 * (m->texture[n].width *
		m->ry_struct.texture_y + m->ry_struct.texture_x))];
}

void		wall(t_global *m, int x, int n)
{
	int y;

	y = m->ry_struct.start;
	while (y <= m->ry_struct.end && y < W)
	{
		m->ry_struct.texture_y = ((m->ry_struct.d *
			m->texture[n].height / m->ry_struct.height) / 256);
		m->ry_struct.d = y * 256 - H * 128 + m->ry_struct.height * 128;
		put_texture_to_img(m, x, y++, n);
	}
	m->ry_struct.y = y;
}

void		wall_directional(t_global *m, int x)
{
	m->ry_struct.y = m->ry_struct.start;
	while (m->ry_struct.y <= m->ry_struct.end && m->ry_struct.y < W)
	{
		(m->ry_struct.step_x < 0) ? (wall(m, x, 0)) : (wall(m, x, 1));
		if (m->ry_struct.hit_side == 1)
			(m->ry_struct.step_y < 0) ? (wall(m, x, 2)) : (wall(m, x, 3));
	}
}

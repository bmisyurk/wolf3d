/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:04:37 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/02 01:04:41 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_vect		set_alpha_and_beta(t_global *m)
{
	double alpha;
	double beta;

	alpha = sqrt(1 + (m->ry_struct.dir.y * m->ry_struct.dir.y)
		/ (m->ry_struct.dir.x * m->ry_struct.dir.x));
	beta = sqrt(1 + (m->ry_struct.dir.x * m->ry_struct.dir.x)
		/ (m->ry_struct.dir.y * m->ry_struct.dir.y));
	return (new_vect(alpha, beta));
}

void				raycasting(t_global *m)
{
	while (m->ry_struct.x < W)
	{
		m->ry_struct.camera = 2 * m->ry_struct.x / (double)W - 1;
		m->ry_struct.dir = new_vect(m->cam_pl.x +
		m->cam_vector.x * m->ry_struct.camera, m->cam_pl.y +
		m->cam_vector.y * m->ry_struct.camera);
		m->ry_struct.pos = new_vect(m->posit_pl.x, m->posit_pl.y);
		m->ry_struct.delta = set_alpha_and_beta(m);
		m->ry_struct.map = new_vect2i(m->ry_struct.pos.x, m->ry_struct.pos.y);
		init_step(m);
		m->ry_struct.height = (int)(H / m->ry_struct.pwd);
		m->ry_struct.start = -m->ry_struct.height / 2 + H / 2;
		m->ry_struct.start = CLAMP(m->ry_struct.start, 1, H - 1);
		m->ry_struct.end = m->ry_struct.height / 2 + H / 2;
		m->ry_struct.end = CLAMP(m->ry_struct.end, 1, H - 1);
		m->ry_struct.tx_num =
		m->map[m->ry_struct.map.x][m->ry_struct.map.y] - 1;
		get_texture(m);
		set_texture(m);
		floor_render(m);
		m->ry_struct.hit = 0;
		m->ry_struct.x++;
	}
}

void				set_texture(t_global *m)
{
	if (!m->ry_struct.hit_side)
		m->ry_struct.wall_x =
	m->ry_struct.pos.y + m->ry_struct.pwd * m->ry_struct.dir.y;
	else
		m->ry_struct.wall_x =
	m->ry_struct.pos.x + m->ry_struct.pwd * m->ry_struct.dir.x;
	m->ry_struct.wall_x -= floor((m->ry_struct.wall_x));
	m->ry_struct.texture_x = (int)(m->ry_struct.wall_x *
		(float)m->texture[m->ry_struct.tx_num].width);
	if (m->ry_struct.hit_side == 1 && m->ry_struct.dir.y < 0)
		m->ry_struct.texture_x = m->texture[m->ry_struct.tx_num].width -
		m->ry_struct.texture_x - 1;
	if (!m->ry_struct.hit_side && m->ry_struct.dir.x > 0)
		m->ry_struct.texture_x = m->texture[m->ry_struct.tx_num].width -
	m->ry_struct.texture_x - 1;
	m->oldtime = m->time;
	m->time = clock();
	m->frametime = (m->time - m->oldtime) / 1000.0;
	m->s_rot = m->frametime * ROT_SPEED;
	m->s_move = m->frametime * MOVE_SPEED;
	if (m->txr)
		wall_directional(m, m->ry_struct.x);
	else
		wall(m, m->ry_struct.x, 2);
}

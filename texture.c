/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 01:43:05 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/02 01:43:10 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		new_texture(t_global *m, int nbr, char *path)
{
	m->texture[nbr].p = mlx_xpm_file_to_image(m->mlx,
		path, &m->texture[nbr].width, &m->texture[nbr].height);
	if (!m->texture[nbr].p)
		return (0);
	m->texture[nbr].img_ptr = mlx_get_data_addr(m->texture[nbr].p,
		&m->texture[nbr].bit_per_pix, &m->texture[nbr].s_line,
		&m->texture[nbr].endian);
	if (!m->texture[nbr].img_ptr)
		return (0);
	return (1);
}

void	texture_start(t_global *m)
{
	m->texture = (t_textur*)malloc(sizeof(t_textur) * 9);
	if (!(new_texture(m, 0, "textures/2.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 1, "textures/3.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 2, "textures/3.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 3, "textures/3.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 4, "textures/3.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 5, "textures/1.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 6, "textures/6.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 7, "textures/3.xpm")))
		out_error("Texture error' files.\n");
	if (!(new_texture(m, 8, "textures/9.xpm")))
		out_error("Texture error' files.\n");
}

void	get_texture(t_global *m)
{
	if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 1)
		m->ry_struct.tx_num = 0;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 2)
		m->ry_struct.tx_num = 1;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 3)
		m->ry_struct.tx_num = 2;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 4)
		m->ry_struct.tx_num = 3;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 8)
		m->ry_struct.tx_num = 4;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 9)
		m->ry_struct.tx_num = 5;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 5)
		m->ry_struct.tx_num = 6;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 6)
		m->ry_struct.tx_num = 7;
	else if (m->map[m->ry_struct.map.x][m->ry_struct.map.y] == 7)
		m->ry_struct.tx_num = 8;
	else
		m->ry_struct.tx_num = 0;
}

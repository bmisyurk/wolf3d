/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:45:01 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/01 21:48:34 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			parse(t_global *m)
{
	if ((m->fd = open(m->name, O_RDONLY)) < 0)
	{
		out_error("ERROR MAP");
		return (0);
	}
	if (!count(m))
		return (0);
	if (m->max_map_x < 3 || m->max_map_y < 3)
	{
		out_error("THE MAP SIZE IS BAAD");
		return (0);
	}
	close(m->fd);
	if ((m->fd = open(m->name, O_RDONLY)) < 0)
		return (0);
	if (!parse_read(m))
		return (0);
	if (!check_wall_holes(m))
		return (0);
	return (1);
}

int			parse_read(t_global *m)
{
	int i;

	i = 0;
	if (!(m->map = (int**)malloc(sizeof(int*) * m->max_map_y + 1)))
		return (0);
	while (i < m->max_map_y)
		if (!(m->map[i++] = parse_line(m)))
			return (0);
	m->map[i] = NULL;
	close(m->fd);
	return (1);
}

int			check_wall_holes(t_global *m)
{
	int j;
	int i;

	j = 0;
	while (j < m->max_map_x)
	{
		if (m->map[0][j] == 0 || m->map[m->max_map_y - 1][j] == 0)
			out_error("THE MAP MUST HAVE NO HOLES");
		j++;
	}
	i = 0;
	while (i < m->max_map_y)
	{
		if (m->map[i][0] == 0 || m->map[i][m->max_map_x - 1] == 0)
			out_error("THE MAP MUST HAVE NO HOLES");
		i++;
	}
	return (1);
}

int			*parse_line(t_global *m)
{
	char	*line;
	int		*new_line;
	int		i;

	if (!(new_line = (int*)malloc(sizeof(int) * m->max_map_x)))
		return (NULL);
	if (get_next_line(m->fd, &line) < 0)
	{
		out_error("ERROR MAP");
		return (NULL);
	}
	i = 0;
	while (i < m->max_map_x)
	{
		if (line[i] == 's')
			line[i] = '0';
		new_line[i] = line[i] - 48;
		i++;
	}
	if (line)
		free(line);
	return (new_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:46:24 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/01 21:46:27 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		count_chars(t_global *m, char *line, int n_line)
{
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (((line[i] > '1' || line[i] < '0') && line[i] != 's'))
			out_error("Wrong symbol in the map");
		if (line[i] == 's')
		{
			(m->posit_pl.x || m->posit_pl.y) ? out_error("Many players!") : 0;
			m->posit_pl.x = n_line;
			m->posit_pl.y = i;
		}
		length++;
		i++;
	}
	m->max_map_x = length;
	(line) ? free(line) : 0;
	return (1);
}

int		count(t_global *m)
{
	char	*line;
	int		i;
	int		temp;

	m->max_map_x = 0;
	m->max_map_y = 0;
	i = 0;
	temp = 0;
	while (get_next_line(m->fd, &line) > 0)
	{
		if (!count_chars(m, line, i))
			return (0);
		if (!m->max_map_y)
			temp = m->max_map_x;
		if (temp != m->max_map_x)
			out_error("Map error");
		m->max_map_y++;
		i++;
	}
	return (1);
}

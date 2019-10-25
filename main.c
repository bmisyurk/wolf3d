/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 00:21:05 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/10/31 00:21:06 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			mlx_win_init(t_global *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, W, H, "WOLF3D");
	m->img = mlx_new_image(m->mlx, W, H);
	m->data = mlx_get_data_addr(m->img, &m->bpp, &m->sizeline, &m->endian);
	m->s_shift = 0.5;
	m->shift = 0;
	m->txr = 0;
	m->cam_pl = new_vect(1, 0);
	m->cam_vector = new_vect(0, 0.66);
	m->up_down = new_vect(0, 0);
	m->left_right = new_vect(0, 0);
	m->time = 0;
	m->oldtime = 0;
	texture_start(m);
	mlx_hook(m->win, 2, 0, key_on, m);
	mlx_hook(m->win, 3, 0, key_off, m);
	mlx_loop_hook(m->mlx, cycle_hooks, m);
	mlx_hook(m->win, 17, 1L << 17, exit_cl, m);
	mlx_loop(m->mlx);
}

void				mlx_create(t_global *m)
{
	mlx_clear_window(m->mlx, m->win);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	put_text(m);
}

void				put_text(t_global *m)
{
	mlx_string_put(m->mlx, m->win, 15, 20, 0xFFFFFF, "RESET : R");
	mlx_string_put(m->mlx, m->win, 15, 40, 0xFFFFFF, "RUN : CTRL");
	mlx_string_put(m->mlx, m->win, 15, 60, 0xFFFFFF, "CHANGE TEXTURE : SPACE");
	mlx_string_put(m->mlx, m->win, 15, 80, 0xFFFFFF, "EXIT : ESC");
}

int					player_pos(t_global *w)
{
	if (w->posit_pl.x <= 0 || w->posit_pl.x >= w->max_map_y)
	{
		ft_putendl("No player flag on the map");
		return (0);
	}
	if (w->posit_pl.y <= 0 || w->posit_pl.y >= w->max_map_x)
	{
		ft_putendl("No player flag on the map");
		return (0);
	}
	w->old_player_pos.x = w->posit_pl.x;
	w->old_player_pos.y = w->posit_pl.y;
	return (1);
}

int					main(int argc, char **argv)
{
	t_global	w;

	if (argc == 2)
	{
		w.name = argv[1];
		w.posit_pl.x = 0;
		w.posit_pl.y = 0;
		if (!parse(&w))
			return (0);
		if (!(player_pos(&w)))
			return (0);
		mlx_win_init(&w);
	}
	else
		ft_putendl("Usage: /wolf3d \"map/\"");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:48:58 by bmisyurk          #+#    #+#             */
/*   Updated: 2018/11/01 21:49:02 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <stdlib.h>
# include <signal.h>
# include "get_next_line.h"

# define W 			800
# define H 			800
# define ESC		53
# define ROT_SPEED	2
# define MOVE_SPEED 5
# define CLAMP(x, lw, h)  (((x) > (h)) ? (h) : (((x) < (lw)) ? (lw) : (x)))

typedef struct	s_vect
{
	double		x;
	double		y;
}				t_vect;

typedef struct	s_vect2i
{
	int			x;
	int			y;
}				t_vect2i;

typedef struct	s_textur
{
	void		*p;
	char		*img_ptr;
	int			bit_per_pix;
	int			s_line;
	int			endian;
	int			width;
	int			height;
}				t_textur;

typedef struct	s_calc
{
	int			x;
	int			y;
	int			d;
	int			step_x;
	int			step_y;
	int			t_num;
	int			texture_x;
	int			texture_y;
	int			hit;
	int			hit_side;
	int			height;
	int			start;
	int			end;
	int			tx_num;
	int			floor_texx;
	int			floor_texy;
	float		wall_x;
	float		camera;
	float		pwd;
	double		floorxwall;
	double		floorywall;
	double		wall_dst;
	double		player_dst;
	t_vect		pos;
	t_vect		dir;
	t_vect		delta;
	t_vect		side;
	t_vect2i	map;
}				t_calc;

typedef struct	s_global
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			info;
	int			shift;
	int			txr;
	int			fd;
	int			max_map_y;
	int			max_map_x;
	int			ceil;
	int			floor;
	int			**map;
	float		s_move;
	float		s_rot;
	float		s_shift;
	double		time;
	double		oldtime;
	double		frametime;
	char		*speed;
	char		*name;
	t_vect		posit_pl;
	t_vect		cam_pl;
	t_vect		cam_vector;
	t_vect		up_down;
	t_vect		left_right;
	t_textur	*texture;
	t_calc		ry_struct;
	t_vect		old_player_pos;
}				t_global;

void			wall(t_global *m, int x, int tx_num);
void			wall_directional(t_global *m, int x);
void			floor_render(t_global *m);
void			floor_render_2(t_global *m);
void			ceiling(t_global *m);
void			add_floor(t_global *m);
void			set_texture(t_global *m);
void			get_texture(t_global *m);
void			texture_start(t_global *m);
void			texture_start2(t_global *m);
int				player_pos(t_global *w);
void			init_dist(t_global *m);
void			init_dist2(t_global *m);
void			init_step(t_global *m);
void			init_step2(t_global *m);
int				parse (t_global *m);
int				*parse_line(t_global *m);
int				check_wall_holes(t_global *m);
int				parse_read(t_global *m);
void			out_error(char *str);
void			put_text(t_global *m);
int				exit_cl(void *click);
void			out_error(char *str);
int				cycle_hooks(t_global *m);
void			mlx_create(t_global *m);
void			clear_window(t_global *m);
t_vect			new_vect(double a, double b);
t_vect2i		new_vect2i(int a, int b);
void			move_forward(t_global *m);
void			move_backwards(t_global *m);
int				key_on(int key, t_global *m);
int				key_off(int key, t_global *m);
int				count_chars(t_global *m,
	char *line, int n_line);
int				count(t_global *m);
void			hook_t_l(t_global *m);
void			hook_t_r(t_global *m);

void			raycasting(t_global *m);
#endif

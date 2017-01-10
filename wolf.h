/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:11:41 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 05:17:40 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include "libft/libft.h"

typedef struct			s_windata
{
	void	*mlx;
	void	*win;
	void	*img;
	int		pos_mx;
	int		size_x;
	int		size_y;
}						t_windata;

typedef struct			s_mapcreat
{
	int **map;
	int nbl;
	int nbc;
}						t_mapcreat;

typedef struct			s_wolfdata
{
	int				**map;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			old_dir_x;
	double			dir_y;
	double			old_plan_x;
	double			plan_x;
	double			plan_y;
	double			cam_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_x;
	double			delta_y;
	double			pw_dist;
	int				line_h;
	int				draw_s;
	int				draw_e;
	int				step_x;
	int				step_y;
	double			movespeed;
	double			rotspeed;
	unsigned int	color;
}						t_wolfdata;

typedef struct			s_env
{
	t_windata	swin;
	t_wolfdata	w;
}						t_env;

int						main(int ac, char **av);
t_wolfdata				get_map(int ac, char **av, t_wolfdata wolf);
void					put_pixel_to_img(int x, int y,
						unsigned long color, t_windata *swin);
unsigned int			get_color(t_env *e);
void					draw_vertline(int x, t_wolfdata wolf, t_windata swin);
int						ft_key_funct(int key, t_env *e);
int						ft_mouse_func(int x, int y, t_env *e);
void					raycast(t_env *e);
void					test_line(char *line);
void					test_map(t_mapcreat data);
void					ft_error(int err_index);

#endif

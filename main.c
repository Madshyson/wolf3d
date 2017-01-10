/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:37:16 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 06:24:21 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_wolfdata			get_pos(t_wolfdata wolf)
{
	int i;
	int j;

	i = 2;
	while (i < wolf.map_x)
	{
		j = 2;
		while (j < wolf.map_y)
		{
			if (wolf.map[i][j] == 0)
			{
				wolf.pos_x = i;
				wolf.pos_y = j;
				return (wolf);
			}
			j++;
		}
		i++;
	}
	ft_error(1);
	return (wolf);
}

static int					quit_cross(int key, t_env *e)
{
	int		keycode;
	t_env	*tmp;

	tmp = e;
	keycode = key;
	exit(1);
	return (0);
}

static t_wolfdata			init_wolf(int ac, char **av)
{
	t_wolfdata wolf;

	wolf.dir_x = -1;
	wolf.dir_y = 0;
	wolf.plan_x = 0;
	wolf.plan_y = 0.66;
	wolf.movespeed = 0.45;
	wolf.rotspeed = 0.15;
	wolf = get_map(ac, av, wolf);
	wolf = get_pos(wolf);
	return (wolf);
}

static t_windata			init_mlx(void)
{
	t_windata swin;

	swin.size_x = 550;
	swin.size_y = 500;
	swin.pos_mx = 0;
	swin.mlx = mlx_init();
	swin.win = mlx_new_window(swin.mlx, swin.size_x, swin.size_y, "Wolf 3D");
	swin.img = mlx_new_image(swin.mlx, swin.size_x, swin.size_y);
	return (swin);
}

int							main(int ac, char **av)
{
	t_env *e;

	e = malloc(sizeof(t_env));
	e->swin = init_mlx();
	e->w = init_wolf(ac, av);
	raycast(e);
	mlx_hook(e->swin.win, 2, (1L << 0), ft_key_funct, e);
	mlx_hook(e->swin.win, 6, (1L << 6), ft_mouse_func, e);
	mlx_hook(e->swin.win, 17, (1L << 17), quit_cross, e);
	mlx_loop(e->swin.mlx);
	return (0);
}

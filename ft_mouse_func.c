/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:44:12 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 06:51:40 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

static void		ft_goleft(t_env *e)
{
	e->w.old_dir_x = e->w.dir_x;
	e->w.dir_x = e->w.dir_x * cos(e->w.rotspeed) - e->w.dir_y *
	sin(e->w.rotspeed);
	e->w.dir_y = e->w.old_dir_x * sin(e->w.rotspeed) + e->w.dir_y *
	cos(e->w.rotspeed);
	e->w.old_plan_x = e->w.plan_x;
	e->w.plan_x = e->w.plan_x * cos(e->w.rotspeed) - e->w.plan_y *
	sin(e->w.rotspeed);
	e->w.plan_y = e->w.old_plan_x * sin(e->w.rotspeed) + e->w.plan_y *
	cos(e->w.rotspeed);
}

static void		ft_goright(t_env *e)
{
	e->w.old_dir_x = e->w.dir_x;
	e->w.dir_x = e->w.dir_x * cos(-e->w.rotspeed) - e->w.dir_y *
	sin(-e->w.rotspeed);
	e->w.dir_y = e->w.old_dir_x * sin(-e->w.rotspeed) + e->w.dir_y *
	cos(-e->w.rotspeed);
	e->w.old_plan_x = e->w.plan_x;
	e->w.plan_x = e->w.plan_x * cos(-e->w.rotspeed) - e->w.plan_y *
	sin(-e->w.rotspeed);
	e->w.plan_y = e->w.old_plan_x * sin(-e->w.rotspeed) + e->w.plan_y *
	cos(-e->w.rotspeed);
}

int				ft_mouse_func(int x, int y, t_env *e)
{
	int pos_y;

	pos_y = y;
	mlx_destroy_image(e->swin.mlx, e->swin.img);
	e->swin.img = mlx_new_image(e->swin.mlx, e->swin.size_x, e->swin.size_y);
	if (x < e->swin.pos_mx || x == 0)
	{
		ft_goleft(e);
	}
	else if (x > e->swin.pos_mx)
	{
		ft_goright(e);
	}
	e->swin.pos_mx = x;
	raycast(e);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:37:21 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 06:27:39 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

static void			mv_up(t_env *e)
{
	if (e->w.map[(int)(e->w.pos_x + e->w.dir_x *
	e->w.movespeed)][(int)(e->w.pos_y)] == 0)
		e->w.pos_x += e->w.dir_x * e->w.movespeed;
	if (e->w.map[(int)(e->w.pos_x)][(int)(e->w.pos_y +
	e->w.dir_y * e->w.movespeed)] == 0)
		e->w.pos_y += e->w.dir_y * e->w.movespeed;
}

static void			mv_down(t_env *e)
{
	if (e->w.map[(int)e->w.pos_x - (int)e->w.dir_x *
	(int)e->w.movespeed][(int)(e->w.pos_y)] == 0)
		e->w.pos_x -= e->w.dir_x * e->w.movespeed;
	if (e->w.map[(int)(e->w.pos_x)][(int)(e->w.pos_y -
	(int)e->w.dir_y * (int)e->w.movespeed)] == 0)
		e->w.pos_y -= e->w.dir_y * e->w.movespeed;
}

static void			mv_funct(int key, t_env *e)
{
	mlx_destroy_image(e->swin.mlx, e->swin.img);
	e->swin.img = mlx_new_image(e->swin.mlx, 800, 800);
	if (key == 125)
		mv_down(e);
	if (key == 126)
		mv_up(e);
	raycast(e);
}

int					ft_key_funct(int key, t_env *e)
{
	if (key == 53)
		exit(1);
	else if (key == 125 || key == 126)
		mv_funct(key, e);
	return (1);
}

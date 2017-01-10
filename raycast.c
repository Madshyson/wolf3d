/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:14:07 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 06:32:48 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			draw_coord(t_env *e)
{
	e->w.line_h = (int)(e->swin.size_y / e->w.pw_dist);
	e->w.draw_s = (int)((-1 * e->w.line_h) / 2) + (e->swin.size_y / 2);
	if (e->w.draw_s < 0)
		e->w.draw_s = 0;
	e->w.draw_e = e->w.line_h / 2 + e->swin.size_y / 2;
	if (e->w.draw_e >= e->swin.size_y)
		e->w.draw_e = e->swin.size_y - 1;
}

static void			set_dda(t_env *e)
{
	while (e->w.hit == 0)
	{
		if (e->w.side_dist_x < e->w.side_dist_y)
		{
			e->w.side_dist_x += e->w.delta_x;
			e->w.map_x += e->w.step_x;
			e->w.side = 0;
		}
		else
		{
			e->w.side_dist_y += e->w.delta_y;
			e->w.map_y += e->w.step_y;
			e->w.side = 1;
		}
		if (e->w.map[e->w.map_x][e->w.map_y] > 0)
			e->w.hit = 1;
	}
	if (e->w.side == 0)
		e->w.pw_dist = (e->w.map_x - e->w.ray_pos_x +
		(1 - e->w.step_x) / 2) / e->w.ray_dir_x;
	else
		e->w.pw_dist = (e->w.map_y - e->w.ray_pos_y
		+ (1 - e->w.step_y) / 2) / e->w.ray_dir_y;
}

static void			pos_set(t_env *e)
{
	if (e->w.ray_dir_x < 0)
	{
		e->w.step_x = -1;
		e->w.side_dist_x = (e->w.ray_pos_x - e->w.map_x) * e->w.delta_x;
	}
	else
	{
		e->w.step_x = 1;
		e->w.side_dist_x = (e->w.map_x + 1 - e->w.ray_pos_x) * e->w.delta_x;
	}
	if (e->w.ray_dir_y < 0)
	{
		e->w.step_y = -1;
		e->w.side_dist_y = (e->w.ray_pos_y - e->w.map_y) * e->w.delta_y;
	}
	else
	{
		e->w.step_y = 1;
		e->w.side_dist_y = (e->w.map_y + 1 - e->w.ray_pos_y) * e->w.delta_y;
	}
}

static void			loop_init(t_env *e, int x)
{
	e->w.cam_x = (2 * x) / (double)e->swin.size_x - 1;
	e->w.ray_pos_x = e->w.pos_x;
	e->w.ray_pos_y = e->w.pos_y;
	e->w.ray_dir_x = e->w.dir_x + (e->w.plan_x * e->w.cam_x);
	e->w.ray_dir_y = e->w.dir_y + (e->w.plan_y * e->w.cam_x);
	e->w.map_x = (int)e->w.ray_pos_x;
	e->w.map_y = (int)e->w.ray_pos_y;
	e->w.delta_x = sqrt(1 + (e->w.ray_dir_y * e->w.ray_dir_y) /
	(e->w.ray_dir_x * e->w.ray_dir_x));
	e->w.delta_y = sqrt(1 + (e->w.ray_dir_x * e->w.ray_dir_x) /
	(e->w.ray_dir_y * e->w.ray_dir_y));
	e->w.hit = 0;
}

void				raycast(t_env *e)
{
	int x;

	x = 0;
	while (x < e->swin.size_x)
	{
		loop_init(e, x);
		pos_set(e);
		set_dda(e);
		draw_coord(e);
		e->w.color = get_color(e);
		draw_vertline(x, e->w, e->swin);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:17:39 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 06:58:00 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned int	get_color(t_env *e)
{
	if (e->w.map[e->w.map_x][e->w.map_y] == 2)
	{
		if ((e->w.side == 1 && e->w.ray_dir_y < 0) ||
		(e->w.side == 0 && e->w.ray_dir_x >= 0))
			return (0x008000);
		else
			return (0x00CC00);
	}
	else if (e->w.map[e->w.map_x][e->w.map_y] == 3)
	{
		if ((e->w.side == 1 && e->w.ray_dir_y < 0) ||
			(e->w.side == 0 && e->w.ray_dir_x >= 0))
			return (0x000080);
		else
			return (0x0000FF);
	}
	else
	{
		if ((e->w.side == 1 && e->w.ray_dir_y < 0) ||
		(e->w.side == 0 && e->w.ray_dir_x >= 0))
			return (0x801100);
		else
			return (0xFF1100);
	}
}

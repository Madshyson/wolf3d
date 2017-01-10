/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:52:08 by mlavanan          #+#    #+#             */
/*   Updated: 2016/05/20 14:51:20 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_vertline(int x, t_wolfdata wolf, t_windata swin)
{
	int y;

	y = 0;
	while (y < swin.size_y)
	{
		if (y < wolf.draw_s)
			put_pixel_to_img(x, y, 0x25e9fc, &swin);
		else if (y <= wolf.draw_e)
			put_pixel_to_img(x, y, wolf.color, &swin);
		else
			put_pixel_to_img(x, y, 0x7b8fb6, &swin);
		y++;
	}
	mlx_put_image_to_window(swin.mlx, swin.win, swin.img, 0, 0);
}

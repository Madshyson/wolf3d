/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:44:19 by mlavanan          #+#    #+#             */
/*   Updated: 2016/05/10 16:33:49 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_pixel_to_img(int x, int y, unsigned long color, t_windata *swin)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		i;

	data = mlx_get_data_addr(swin->img, &bpp, &size_line, &endian);
	i = x * 4 + y * size_line;
	if (x < swin->size_x && x >= 0 && y < swin->size_y && y >= 0)
	{
		data[i] = color % 256;
		color /= 256;
		data[i + 1] = color % 256;
		color /= 256;
		data[i + 2] = color % 256;
		color /= 256;
		data[i + 3] = 0;
		color /= 256;
	}
}

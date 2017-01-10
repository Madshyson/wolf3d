/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 19:47:41 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 07:04:08 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			test_map(t_mapcreat data)
{
	int i;
	int j;

	i = 0;
	if (data.nbl <= 4 || data.nbc <= 4)
		ft_error(2);
	while (i < data.nbl)
	{
		j = 0;
		while (j < data.nbc)
		{
			if (((i == 0) || (i == data.nbl - 1) || (j == 0) ||
			(j == data.nbc - 1)) && data.map[i][j] != 1)
				ft_error(1);
			j++;
		}
		i++;
	}
}

void			test_line(char *line)
{
	unsigned long i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (i % 2 == 0 && !ft_isdigit(line[i]))
			ft_error(1);
		if (i % 2 == 1 && line[i] != ' ')
			ft_error(1);
		i++;
	}
}

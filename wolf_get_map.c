/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:06:30 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/11 07:05:16 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

static t_wolfdata			init(t_mapcreat data, t_wolfdata wolf)
{
	int i;
	int j;

	i = 0;
	wolf.map_x = data.nbc;
	wolf.map_y = data.nbl;
	wolf.map = malloc(sizeof(int *) * data.nbl);
	while (i < data.nbl)
	{
		j = 0;
		wolf.map[i] = malloc(sizeof(int) * data.nbc);
		while (j < data.nbc)
		{
			wolf.map[i][j] = data.map[i][j];
			j++;
		}
		i++;
	}
	return (wolf);
}

static t_mapcreat			cpy_data(t_mapcreat data)
{
	t_mapcreat		tmp;
	int				i;
	int				j;

	i = 0;
	tmp.nbl = data.nbl;
	tmp.nbc = data.nbc;
	tmp.map = malloc(sizeof(int *) * tmp.nbl + 1);
	while (i < tmp.nbl)
	{
		j = 0;
		tmp.map[i] = malloc(sizeof(int) * tmp.nbc);
		while (j < tmp.nbc)
		{
			tmp.map[i][j] = data.map[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

static t_mapcreat			get_data(char **line, t_mapcreat data, int nl)
{
	int			i;
	t_mapcreat	tmp;

	tmp = cpy_data(data);
	tmp.map[nl] = malloc(sizeof(int) * tmp.nbc);
	i = 0;
	while (i < tmp.nbc)
	{
		tmp.map[nl][i] = ft_atoi(line[i]);
		i++;
	}
	return (tmp);
}

static t_mapcreat			create_map(char *line, int nl, t_mapcreat data)
{
	char	**split;

	test_line(line);
	split = ft_strsplit(line, ' ');
	if (nl == 0)
		data.nbc = ft_datalen(split);
	if (data.nbc != ft_datalen(split))
		ft_error(1);
	data = get_data(split, data, nl);
	data.nbl = nl + 1;
	return (data);
}

t_wolfdata					get_map(int ac, char **av, t_wolfdata wolf)
{
	int			fd;
	int			nbl;
	int			ret;
	char		*line;
	t_mapcreat	map_struct;

	nbl = 0;
	map_struct.nbl = 0;
	if (ac == 1)
		ft_error(0);
	if (ac > 2)
		ft_error(2);
	if (ft_strcmp("/dev/random", av[1]) == 0)
		ft_error(1);
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map_struct = create_map(line, nbl, map_struct);
		nbl++;
		free(line);
	}
	test_map(map_struct);
	wolf = init(map_struct, wolf);
	return (wolf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:51:21 by mlavanan          #+#    #+#             */
/*   Updated: 2016/06/07 18:19:30 by mlavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_error(int err_index)
{
	if (err_index == 0)
		ft_putendl("no map detected, TRY AGAIN");
	else if (err_index == 1)
		ft_putendl("map not well formated, TRY AGAIN");
	else if (err_index == 2)
		ft_putendl("too much map, TRY AGAIN");
	exit(1);
}

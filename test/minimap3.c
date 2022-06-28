/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:24:20 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/28 22:13:24 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	max_len(t_rc *rc, t_data *data)
{
	if (abs(rc->mapx - (int)data->pos_x) > 4)
		return (1);
	if (abs(rc->mapy - (int)data->pos_y) > 4)
		return (1);
	return (0);
}

void	print_floor_wall(t_data *data)
{
	print_wall(data);
	print_floor(data);
}

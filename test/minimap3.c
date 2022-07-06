/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:24:20 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/06 19:00:03 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	max_len(t_rc *rc, t_data *data, float angle)
{
	if (rc->mod == 0)
		return (0);
	if ((PI / 4) - 0.1 <= angle && angle <= (5 * PI / 4) + 0.1)
	{
		if (fabsf(rc->mapx - data->pos_x) > 5.5)
			return (1);
		if (fabsf(rc->mapy - data->pos_y) > 5.5)
			return (1);
	}
	else
	{
		if (fabsf(rc->mapx - data->pos_x) > 4.5)
			return (1);
		if (fabsf(rc->mapy - data->pos_y) > 4.5)
			return (1);
	}
	return (0);
}

int	limit(t_minimap *map)
{
	if (10 < map->x_win || 10 < map->y_win)
		return (1);
	if (map->x_win == 10)
	{
		if (map->diff_x < 0)
			return (1);
	}
	if (map->y_win == 10)
	{
		if (map->diff_y < 0)
			return (1);
	}
	return (0);
}

float	angle_correction(float angle)
{
	if (angle < 0)
		return (angle + (2 * PI));
	if (angle > (2 * PI))
		return (angle - (2 * PI));
	return (angle);
}

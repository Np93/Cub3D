/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:24:56 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 22:28:37 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	print_wall(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_ysize)
	{
		x = -1;
		while (++x < data->map_xsize)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win_m, data->w_mmap,
					x * PMAP, y * PMAP);
		}
	}
}

void	print_floor(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_ysize)
	{
		x = -1;
		while (++x < data->map_xsize)
		{
			if (data->map[y][x] != '1')
				mlx_put_image_to_window(data->mlx, data->win_m, data->f_mmap,
					x * PMAP, y * PMAP);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:24:56 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/28 21:43:16 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"
/*
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
}*/

void	diff(t_data *data, t_minimap *map)
{
		map->diff_x = data->pos_x - (int)data->pos_x - 0.5;
		map->diff_y = data->pos_y - (int)data->pos_y - 0.5;
}

void	print_wall(t_data *data)
{
	t_minimap	map;

	diff(data, &map);
	if (4 <= data->pos_y)
		map.y_win = 0;
	else
		map.y_win = 1;
	map.y = (int)(data->pos_y - 4);
	while (map.y <= (int)(data->pos_y + 4))
	{
		map.x = (int)(data->pos_x - 4);
		if (4 <= data->pos_x)
			map.x_win = 0;
		else
			map.x_win = 1;
		while (map.x <= (int)(data->pos_x + 4))
		{
			if (0 <= map.x && map.x < data->map_xsize && 0 <= map.y && map.y < data->map_ysize)
			{
				if (data->map[map.y][map.x] == '1')
				{
					mlx_put_image_to_window(data->mlx, data->win_m, data->w_mmap,
						(map.x_win - map.diff_x) * PMAP + PMAP,
						(map.y_win - map.diff_y) * PMAP + PMAP);
				}
			}
			map.x++;
			map.x_win++;
		}
		map.y++;
		map.y_win++;
	}
}

void	print_floor(t_data *data)
{
	t_minimap	map;

	diff(data, &map);
	map.y_win = 0;
	map.y = (int)(data->pos_y - 4);
	while (map.y <= (int)(data->pos_y + 4))
	{
		map.x = (int)(data->pos_x - 4);
		map.x_win = 0;
		while (map.x <= (int)(data->pos_x + 4))
		{
			if ((0 <= map.x && map.x < data->map_xsize) && (0 <= map.y && map.y < data->map_ysize))
			{
				if (data->map[map.y][map.x] != '1' && data->map[map.y][map.x] != '\n')
				{
					mlx_put_image_to_window(data->mlx, data->win_m, data->f_mmap,
						(map.x_win - map.diff_x) * PMAP + PMAP,
						(map.y_win - map.diff_y) * PMAP + PMAP);
				}
			}
			map.x++;
			map.x_win++;
		}
		map.y++;
		map.y_win++;
	}
}

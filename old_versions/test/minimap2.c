/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:24:56 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/16 23:08:39 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	diff(t_data *data, t_minimap *map)
{
		map->diff_x = data->pos_x - (int)data->pos_x - 0.5;
		map->diff_y = data->pos_y - (int)data->pos_y - 0.5;
}

void	print_wall(t_data *data)
{
	t_minimap	map;

	diff(data, &map);
	if (data->pos_y <= 6)
		map.y_win = 0;
	else
		map.y_win = -1;
	map.y = (int)(data->pos_y - 6);
	while (map.y <= (int)(data->pos_y + 5))
	{
		map.x = (int)(data->pos_x - 6);
		if (data->pos_x <= 6)
			map.x_win = 0;
		else
			map.x_win = -1;
		print_wall2(data, &map);
		map.y++;
		map.y_win++;
	}
}

void	print_wall2(t_data *data, t_minimap *map)
{
	while (map->x <= (int)(data->pos_x + 5))
	{
		if (0 <= map->x && map->x < data->map_xsize && 0 <= map->y
			&& map->y < data->map_ysize)
		{
			if (data->map[map->y][map->x] == '1')
			{
				if (!limit(map))
					mlx_put_image_to_window(data->mlx, data->win, data->w_mmap,
						(map->x_win - map->diff_x) * PMAP,
						(map->y_win - map->diff_y) * PMAP);
			}
		}
		else
		{
			if (!limit(map))
				mlx_put_image_to_window(data->mlx, data->win, data->w_mmap,
					(map->x_win - map->diff_x) * PMAP,
					(map->y_win - map->diff_y) * PMAP);
		}
		map->x++;
		map->x_win++;
	}
}

void	print_floor(t_data *data)
{
	t_minimap	map;

	diff(data, &map);
	if (data->pos_y <= 6)
		map.y_win = 0;
	else
		map.y_win = -1;
	map.y = (int)(data->pos_y - 6);
	while (map.y <= (int)(data->pos_y + 5))
	{
		map.x = (int)(data->pos_x - 6);
		if (data->pos_x <= 6)
			map.x_win = 0;
		else
			map.x_win = -1;
		print_floor2(data, &map);
		map.y++;
		map.y_win++;
	}
}

void	print_floor2(t_data *data, t_minimap *map)
{
	while (map->x <= (int)(data->pos_x + 5))
	{
		if ((0 <= map->x && map->x < data->map_xsize) && (0 <= map->y
				&& map->y < data->map_ysize))
		{
			if (data->map[map->y][map->x] != '1')
			{
				if (!limit(map))
					mlx_put_image_to_window(data->mlx, data->win, data->f_mmap,
						(map->x_win - map->diff_x) * PMAP,
						(map->y_win - map->diff_y) * PMAP);
			}
		}
		map->x++;
		map->x_win++;
	}
}

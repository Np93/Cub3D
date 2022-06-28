/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:24:56 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/28 02:53:04 by rmonney          ###   ########.fr       */
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

int	diff(t_data *data, char xy)
{
	int	inter;
	int	map_case;

	if (xy == 'x')
	{
		inter = (int)(data->pos_x * 10);
		map_case = (int)(data->pos_x) * 10;
	}
	else
	{
		inter = (int)(data->pos_y * 10);
		map_case = (int)(data->pos_y) * 10;
	}

	if (xy == 'x')
		printf("diff_x = %d\n", (inter - map_case - 5));
	else
		printf("diff_y = %d\n", (inter - map_case - 5));

	return ((inter - map_case - 5));
}

void	print_wall(t_data *data)
{
	int	x;
	int	y;
	int	x_win;
	int	y_win;
	int	diff_x;
	int	diff_y;

	diff_x = diff(data, 'x');
	diff_y = diff(data, 'y');
	y_win = 0;
	y = (int)(data->pos_y - 5);
	while (y <= (int)(data->pos_y + 5))
	{
		x = (int)(data->pos_x - 5);
		x_win = 0;
		while (x <= (int)(data->pos_x + 5))
		{
			if (0 <= x && x < data->map_xsize && 0 <= y && y < data->map_ysize)
			{
				if (data->map[y][x] == '1')
					mlx_put_image_to_window(data->mlx, data->win_m, data->w_mmap,
						(x_win * PMAP - (diff_x * 5)), (y_win * PMAP - (diff_y * 5)));
			}
			x++;
			x_win++;
		}
		y++;
		y_win++;
	}
}

void	print_floor(t_data *data)
{
	int	x;
	int	y;
	int	x_win;
	int	y_win;
	int	diff_x;
	int	diff_y;

	diff_x = diff(data, 'x');
	diff_y = diff(data, 'y');
	y_win = 0;
	y = (int)(data->pos_y - 5);
	while (y <= (int)(data->pos_y + 5))
	{
		x = (int)(data->pos_x - 5);
		x_win = 0;
		while (x <= (int)(data->pos_x + 5))
		{
			if ((0 <= x && x < data->map_xsize) && (0 <= y && y < data->map_ysize))
			{
				if (data->map[y][x] != '1')
				{
					mlx_put_image_to_window(data->mlx, data->win_m, data->f_mmap,
						x_win * PMAP - (diff_x * 5), y_win * PMAP - (diff_y * 5));
				}
			}
			x++;
			x_win++;
		}
		y++;
		y_win++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:43:58 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/21 20:32:49 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	print_minimap(t_data *data)
{
	int	x;
	int	y;
	y = 0;
	while (y < data->map_ysize)
	{
		x = 0;
		while (x < data->map_xsize)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->w_mmap,
					x * 50, y * 50);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->f_mmap,
					x * 50, y * 50);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->red_pix,
		(data->pos_x * 50), (data->pos_y * 50));
	
//		if (data->pos_x - (int)data->pos_x > 0.95)
//			data->pos_x += 0.01;
//	if (0.99 < data->pos_x / (int)data->pos_x && data->pos_x / (int)data->pos_x < 1.01)
//		printf("cause float x = %f and int x = %d the division resut is %f\n", data->pos_x, (int)data->pos_x,
//			(int)data->pos_x / data->pos_x);
	print_pov_angle(data);
}
/*
float	collipov(t_data *data, float angle)
{
	float	a;
	float	x;
	float	y;
	int		ok;

	ok = 1;
	a = 0;
	while (ok)
	{
		x = data->pos_x + (cos(angle) * a);
		y = data->pos_y - (sin(angle) * a);

//		if (x - (int)x > 0.9)
//			x += 0.01;


			if (data->map[(int)(y)][(int)(x)] == '1')
				ok = 0;
			else
				a+= 0.1;
	}
	return (a * 50);
}

void	print_pov_angle(t_data *data)
{
	float	x;
	float	a;
	float	max_len;

//	a = -1;
	a = 0;
//	while (a <= 1)
	while (a == 0)
	{
		x = 5.0;
		max_len = collipov(data, (data->look + a));
		while (x <= max_len)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->red_pix,
				(data->pos_x * 50) + (cos(data->look + a) * x),
				(data->pos_y * 50) - (sin(data->look + a) * x));
			x += 0.5;
		}
		a += 0.05;
	}
}*/

void	collipov(t_data *data, t_rc *rc, float angle)
{
	if (angle < (M_PI / 2) || angle > ((3 * M_PI) / 2))
		rc->distx = (rc->mapx + 1) - data->pos_x;
	else
		rc->distx = data->pos_x - rc->mapx;
	if (angle < M_PI)
		rc->disty = data->pos_y - rc->mapy;
	else
		rc->disty = (rc->mapy + 1) - data->pos_y;

	rc->lenx = sqrt(powf(rc->distx, 2) + powf((tan(angle) * rc->distx), 2)) * 50;
	rc->leny = sqrt(powf(rc->disty, 2) + powf((tan(angle - (M_PI / 2)) * rc->disty), 2)) * 50;	
}

void	print_pov_angle(t_data *data)
{
	t_rc	rc;

	rc.mapx = (int)data->pos_x;
	rc.mapy = (int)data->pos_y;
	rc.b = -0.5;
	while (rc.b <= 0.5)
	{
		collipov(data, &rc, data->look + rc.b);
		rc.a = 1;
		while (rc.a <= rc.lenx && rc.a <= rc.leny)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->red_pix,
				(data->pos_x * 50) + (cos(data->look + rc.b) * rc.a),
				(data->pos_y * 50) - (sin(data->look + rc.b) * rc.a));
			rc.a += 0.5;
		}
		rc.b += 0.1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:43:58 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 00:12:10 by rmonney          ###   ########.fr       */
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
			if (data->map[y][x] != '1')
				mlx_put_image_to_window(data->mlx, data->win, data->f_mmap,
					x * 50, y * 50);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->red_pix,
		(data->pos_x * 50), (data->pos_y * 50));
	print_pov_angle(data);
}

void	collipov(t_data *data, t_rc *rc, float angle)
{
	rc->mapx = (int)data->pos_x;
	rc->mapy = (int)data->pos_y;
	rc->stepx = 1;
	rc->stepy = 1;
	if (angle < (M_PI / 2) || angle > ((3 * M_PI) / 2))
		rc->distx = (rc->mapx + 1) - data->pos_x;
	else
	{
		rc->distx = data->pos_x - rc->mapx;
		rc->stepx *= -1;
	}
	if (angle < M_PI)
	{
		rc->disty = data->pos_y - rc->mapy;
		rc->stepy *= -1;
	}
	else
		rc->disty = (rc->mapy + 1) - data->pos_y;
	rc->lenx = sqrt(powf(rc->distx, 2)
			+ powf((tan(angle) * rc->distx), 2)) * 50;
	rc->leny = sqrt(powf(rc->disty, 2)
			+ powf((tan(angle - (M_PI / 2)) * rc->disty), 2)) * 50;
	collipov2(data, rc, angle);
}

void	collipov2(t_data *data, t_rc *rc, float angle)
{
	rc->deltax = sqrt(1 + powf(tan(angle), 2)) * 50;
	rc->deltay = sqrt(1 + powf(tan(angle - (M_PI / 2)), 2)) * 50;
	rc->hit = 0;
	while (!rc->hit)
	{
		if (rc->lenx < rc->leny)
		{
			rc->lenx += rc->deltax;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->leny += rc->deltay;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (data->map[rc->mapy][rc->mapx] == '1')
			rc->hit = 1;
	}
	if (rc->side == 0)
		rc->lenx -= rc->deltax;
	else
		rc->leny -= rc->deltay;
}

void	print_pov_angle(t_data *data)
{
	t_rc	rc;

	rc.b = -0.8;
	while (rc.b <= 0.8)
	{
		collipov(data, &rc, data->look + rc.b);
		rc.a = 1;
		while (rc.a <= rc.lenx && rc.a <= rc.leny)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->red_pix,
				(data->pos_x * 50) + (cos(data->look + rc.b) * rc.a),
				(data->pos_y * 50) - (sin(data->look + rc.b) * rc.a));
			rc.a += 1;
		}
		rc.b += 0.05;
	}
}

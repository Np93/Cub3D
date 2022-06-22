/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:43:58 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 22:41:36 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	print_minimap(t_data *data)
{
	print_floor(data);
	mlx_put_image_to_window(data->mlx, data->win_m, data->green_pix,
		(data->pos_x * PMAP + 1), (data->pos_y * PMAP + 1));
	print_pov_angle(data);
	print_wall(data);
}

float	angle_correction(float angle)
{
	if (angle < 0)
		return (angle + (2 * PI));
	if (angle > (2 * PI))
		return (angle - (2 * PI));
	return (angle);
}

void	collipov(t_data *data, t_rc *rc, float angle)
{
	rc->mapx = (int)data->pos_x;
	rc->mapy = (int)data->pos_y;
	angle = angle_correction(angle);
	rc->stepx = 1;
	rc->stepy = 1;
	if ((PI / 2) > angle || angle > ((3 * PI) / 2))
		rc->distx = (rc->mapx + 1) - data->pos_x;
	else
	{
		rc->distx = data->pos_x - rc->mapx;
		rc->stepx *= -1;
	}
	if (angle <= PI)
	{
		rc->disty = data->pos_y - rc->mapy;
		rc->stepy *= -1;
	}
	else
		rc->disty = (rc->mapy + 1) - data->pos_y;
	rc->lenx = sqrt(powf(rc->distx, 2)
			+ powf((tan(angle) * rc->distx), 2)) * PMAP;
	rc->leny = sqrt(powf(rc->disty, 2)
			+ powf((tan(angle - (PI / 2)) * rc->disty), 2)) * PMAP;
	collipov2(data, rc, angle);
}

void	collipov2(t_data *data, t_rc *rc, float angle)
{
	rc->deltax = sqrt(1 + powf(tan(angle), 2)) * PMAP;
	rc->deltay = sqrt(1 + powf(tan(angle - (PI / 2)), 2)) * PMAP;
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

	rc.b = -0.9;
	while (rc.b <= 0.9)
	{
		collipov(data, &rc, data->look + rc.b);
		rc.a = 5;
		while (rc.a <= rc.lenx && rc.a <= rc.leny)
		{
			if (rc.a < 80)
				mlx_put_image_to_window(data->mlx, data->win_m, data->red_max,
					(data->pos_x * PMAP) + (cos(data->look + rc.b) * rc.a),
					(data->pos_y * PMAP) - (sin(data->look + rc.b) * rc.a));
			else if (80 <= rc.a && rc.a < 150)
				mlx_put_image_to_window(data->mlx, data->win_m, data->red_max,
					(data->pos_x * PMAP) + (cos(data->look + rc.b) * rc.a),
					(data->pos_y * PMAP) - (sin(data->look + rc.b) * rc.a));
			else
				mlx_put_image_to_window(data->mlx, data->win_m, data->red_max,
					(data->pos_x * PMAP) + (cos(data->look + rc.b) * rc.a),
					(data->pos_y * PMAP) - (sin(data->look + rc.b) * rc.a));
			rc.a += 2;
		}
		rc.b += 0.03;
	}
}

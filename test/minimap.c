/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:43:58 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/07 19:00:39 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	print_minimap(t_data *data)
{
	print_floor(data);
	print_pov_angle(data);
	mlx_put_image_to_window(data->mlx, data->win, data->green_pix,
		(5.5 * PMAP - 2), (5.5 * PMAP - 2));
	print_wall(data);
	mlx_put_image_to_window(data->mlx, data->win, data->map_frame, 0, 0);
}

void	collipov(t_data *data, t_rc *rc, float angle, int mod)
{
	rc->mod = mod;
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
		if (data->map[rc->mapy][rc->mapx] == '1' || max_len(rc, data, angle))
			rc->hit = 1;
	}
	if (rc->side == 0)
		rc->dist = rc->lenx - rc->deltax;
	else
		rc->dist = rc->leny - rc->deltay;
	collipov3(data, rc, angle);
}

void	collipov3(t_data *data, t_rc *rc, float angle)
{
	if (rc->mod == 0)
		rc->dist /= PMAP;
	if (rc->side == 0)
	{
		rc->wallx = data->pos_y + rc->dist * rc->stepy * sin(angle);
		if (PI / 2 <= angle && angle <= 3 * PI / 2)
			rc->what_wall = 'e';
		else
			rc->what_wall = 'w';
	}
	else
	{
		rc->wallx = data->pos_x + rc->dist * rc->stepx * cos(angle);
		if (0 <= angle && angle <= PI)
			rc->what_wall = 's';
		else
			rc->what_wall = 'n';
	}
	rc->wallx -= floor(rc->wallx);
	if (rc->side == 1 && rc->stepy < 0)
		rc->wallx = 1 - rc->wallx;
	if (rc->side == 0 && rc->stepx > 0)
		rc->wallx = 1 - rc->wallx;
	rc->texx = rc->wallx * PTEX;
	if (rc->side == 0 && rc->stepy < 0)
		rc->texx = PTEX - rc->texx - 1;
	if (rc->side == 1 && rc->stepx > 0)
		rc->texx = PTEX - rc->texx - 1;
}

void	print_pov_angle(t_data *data)
{
	t_rc	rc;

	rc.b = 0.95; // 38rayons
	rc.x = 0;
	while (rc.b >= -0.95)
	{
		collipov(data, &rc, data->look + rc.b, 1);
		rc.a = 5;
		if (rc.x++ % 2)
			rc.a = 7.5;
		while (rc.a <= rc.dist && rc.a < 6.5 * PMAP)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->red_pix,
				(5.5 * PMAP) + (cos(data->look + rc.b) * rc.a),
				(5.5 * PMAP) - (sin(data->look + rc.b) * rc.a));
			rc.a += 5;
			if (rc.a < 90 && (-0.01 >= rc.b && rc.b <= 0.01))
				rc.a += 1;
			if (-0.01 <= rc.b && rc.b <= 0.01)
				rc.a -= 4.3;
		}
		rc.b -= 0.05;
	}
}

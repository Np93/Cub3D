/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:43:58 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 22:45:11 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:43:58 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/13 02:47:47 by rmonney          ###   ########.fr       */
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


/*
void	collipov(t_data *data, t_rc *rc, float angle, int mod)
{
	rc->mod = mod;
	int	dirx = -1;
	int	diry = 0;
	float planex = 0;
	float planey = -0.66;

	float camerax = 2 * rc->num / (float)RESX - 1;
	float raydirx = dirx + planex * camerax;
	float raydiry = diry + planey * camerax;

	rc->mapx = (int)data->pos_x;
	rc->mapy = (int)data->pos_y;
	angle = angle_correction(angle);
	rc->deltax = fabs(1 / raydirx);
	rc->deltay = fabs(1 / raydiry);
	rc->hit = 0;

	if (raydirx < 0)
	{
		rc->stepx = -1;
		rc->distx = (data->pos_x - rc->mapx) * rc->deltax;
	}
	else
	{
		rc->stepx = 1;
		rc->distx = (rc->mapx + 1 - data->pos_x) * rc->deltax;	
	}
	if (raydiry < 0)
	{
		rc->stepy = 1;
		rc->disty = (data->pos_y - rc->mapy) * rc->deltay;
	}

}*/









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
		if (rc->stepy < 0)
			rc->wallx = data->pos_y + rc->dist * rc->stepy * sin(angle);
		else
			rc->wallx = data->pos_y - rc->dist * rc->stepy * sin(angle);
		if (PI / 2 <= angle && angle <= 3 * PI / 2)
			rc->what_wall = 'e';
		else
			rc->what_wall = 'w';
	}
	else
	{
		if (rc->stepx > 0)
			rc->wallx = data->pos_x + rc->dist * rc->stepx * cos(angle);
		else
			rc->wallx = data->pos_x - rc->dist * rc->stepx * cos(angle);
		if (0 <= angle && angle <= PI)
			rc->what_wall = 's';
		else
			rc->what_wall = 'n';
	}
	collipov4(data, rc, angle);
}

void	collipov4(t_data *data, t_rc *rc, float angle)
{
/*
//	if (rc->side == 1)
		rc->fe_diff = fabs(rc->dist - cos(fabs(data->look - angle)) * rc->dist);
//	else
//		rc->fe_diff = fabs(rc->dist - sin(fabs((data->look + PI) - (angle + PI))) * rc->dist);
	if (rc->mod == 0)
	{
	//	if (rc->side == 1)
			rc->dist -= rc->fe_diff;	//calcul avec le plan CAMX
	}
	if (rc->mod == 1)
	{
		if (rc->side == 1)
			printf("fisheye correction = %f\n", rc->fe_diff);
	}*/

	rc->wallx -= floor(rc->wallx);
	rc->texx = (int)(rc->wallx * PTEX);
	if (rc->side == 0 && rc->stepx < 0)
		rc->texx = PTEX - rc->texx;
	if (rc->side == 1 && rc->stepy > 0)
		rc->texx = PTEX - rc->texx;

	if (data && angle)
		printf("");

	rc->fe_diff = fabs(rc->dist - cos(fabs(data->look - angle)) * rc->dist);
	if (rc->mod == 0)
	{
	//	if ((PI / 4 < data->look && data->look < 3 * PI / 4)
	//			|| (5 * PI / 4 < data->look && data->look < 7 * PI / 4))
	//	{
	//		if (rc->side == 1)
				if (rc->fe_diff > 30)
					rc->fe_diff = 30;
				rc->dist = fabs( cos(data->look - angle) ) * rc->dist;
	//	}
	}
	if (rc->mod == 0)
	{
		if (rc->num % 100 == 0)
			printf("fisheye correction for ray[%d] = %f\n", rc->num,  rc->fe_diff);
		if (rc->num == 1920)
			printf("\n\n");
	}
}

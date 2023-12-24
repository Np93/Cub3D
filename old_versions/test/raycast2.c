/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:34:33 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/14 02:05:42 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycast3(t_data *data, t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (data->pos_x - r->mapx) * r->deltax;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1 - data->pos_x) * r->deltax;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (data->pos_y - r->mapy) * r->deltay;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1 - data->pos_y) * r->deltay;
	}	
}

void	raycast4(t_data *data, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltax;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltay;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (data->map[r->mapy][r->mapx] == '1')
			r->hit = 1;
	}
	if (r->side == 0)
		r->perpwalldist = r->sidedistx - r->deltax;
	else
		r->perpwalldist = r->sidedisty - r->deltay;
}

void	raycast5(t_data *data, t_ray *r)
{
	if (r->side == 0)
	{
		if (0 < r->stepx)
			r->what_wall = 'w';
		else
			r->what_wall = 'e';
		r->wallx = data->pos_y + r->perpwalldist * r->raydiry;
	}
	else
	{
		if (0 < r->stepy)
			r->what_wall = 'n';
		else
			r->what_wall = 's';
		r->wallx = data->pos_x + r->perpwalldist * r->raydirx;
	}
	r->wallx -= floor(r->wallx);
	r->texx = (int)(r->wallx * (float)PTEX);
	if (r->side == 0 && r->raydirx < 0)
		r->texx = PTEX - r->texx - 1;
	if (r->side == 1 && r->raydiry > 0)
		r->texx = PTEX - r->texx - 1;
}

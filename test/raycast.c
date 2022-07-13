/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/13 05:18:06 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	cpy_pixel(t_tex *dst, t_tex *src, t_rc *rc)
{
	int	i;

	rc->srcy = (float)(rc->dsty - rc->starth) / rc->h * PTEX;
	i = -1;
	while (++i <= 3)
		dst->data_addr[(4 * rc->dstx) + (rc->dsty * dst->size_line) + i]
			= src->data_addr[(4 * rc->texx) + (rc->srcy * src->size_line) + i];
}

void	cpy_color(t_tex *dst, char color[3], t_rc *rc)
{
	dst->data_addr[(4 * rc->dstx) + (rc->dsty * dst->size_line)]
		= color[0];
	dst->data_addr[(4 * rc->dstx) + (rc->dsty * dst->size_line) + 1]
		= color[1];
	dst->data_addr[(4 * rc->dstx) + (rc->dsty * dst->size_line) + 2]
		= color[2];
	dst->data_addr[(4 * rc->dstx) + (rc->dsty * dst->size_line) + 3] = 0;
}

void	what_hit(t_rc *rc)
{
	if (rc->what_wall == 'n')
		printf("ray[%d] hit wall NORTH ", rc->num);
	if (rc->what_wall == 's')
		printf("ray[%d] hit wall SOUTH ", rc->num);
	if (rc->what_wall == 'e')
		printf("ray[%d] hit wall EAST ", rc->num);
	if (rc->what_wall == 'w')
		printf("ray[%d] hit wall WEST ", rc->num);
	printf("at dist = [%f], wallx = [%f] & texx = [%d]\n",
		rc->dist, rc->wallx, rc->texx);
	rc->num++;
	if (rc->num == 100)
		printf("\n\n");
}
/*
//1920rayons
void	raycast(t_data *data)
{
	t_rc	rc;

	rc.num = 0;
	rc.b = 0.96;
	collipov(data, &rc, data->look, 0);
	rc.dist_saved = rc.dist;
	while (rc.b >= -0.96)
	{
		collipov(data, &rc, data->look + rc.b, 0);
		make_final(data, &rc);
		rc.b -= 0.001;
		rc.num++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->end.img, 0, 0);
}*/

void	cpy_pixel_ray(t_tex *dst, t_tex *src, t_ray *r)
{
	int	i;

	r->srcy = (float)(r->dsty - r->starth) / r->h * PTEX;
	i = -1;
	while (++i <= 3)
		dst->data_addr[(4 * r->dstx) + (r->dsty * dst->size_line) + i]
			= src->data_addr[(4 * r->texx) + (r->srcy * src->size_line) + i];
}

void	cpy_color_ray(t_tex *dst, char color[3], t_ray *r)
{
	dst->data_addr[(4 * r->dstx) + (r->dsty * dst->size_line)]
		= color[0];
	dst->data_addr[(4 * r->dstx) + (r->dsty * dst->size_line) + 1]
		= color[1];
	dst->data_addr[(4 * r->dstx) + (r->dsty * dst->size_line) + 2]
		= color[2];
	dst->data_addr[(4 * r->dstx) + (r->dsty * dst->size_line) + 3] = 0;
}

void	make_final_ray(t_data *data, t_ray *r)
{
	r->h = (int)(HEIGHT / r->perpwalldist);
	r->starth = -r->h / 2 + RESY / 2;
	r->endh = r->h / 2 + RESY / 2;
	r->dstx = r->x;
	r->dsty = 0;
	while (r->dsty < RESY - 1)
	{
		if (r->dsty < r->starth + 1 / PTEX * r->perpwalldist)
			cpy_color_ray(&data->end, data->up_char, r);
		else if (r->starth <= r->dsty && r->dsty < r->endh)
		{
			if (r->what_wall == 'n')
				cpy_pixel_ray(&data->end, &data->north, r);
			if (r->what_wall == 's')
				cpy_pixel_ray(&data->end, &data->south, r);
			if (r->what_wall == 'e')
				cpy_pixel_ray(&data->end, &data->east, r);
			if (r->what_wall == 'w')
				cpy_pixel_ray(&data->end, &data->west, r);
		}
		else if (r->endh <= r->dsty)
			cpy_color_ray(&data->end, data->down_char, r);
		r->dsty++;
	}
}

void	raycast2(t_data *data, t_ray *r)
{
	r->mapx = (int)data->pos_x;
	r->mapy = (int)data->pos_y;
	r->deltax = fabs(1 / r->raydirx);
	r->deltay = fabs(1 / r->raydiry);
	r->hit = 0;
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

void	raycast(t_data *data)
{
	t_ray	r;

	r.x = 0;
	while (r.x < RESX)
	{
		r.camerax = 2 * r.x / (float)RESX - 1;
		r.raydirx = data->dirx + data->planex * r.camerax;
		r.raydiry = data->diry + data->planey * r.camerax;
		raycast2(data, &r);
		make_final_ray(data, &r);
		r.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->end.img, 0, 0);
}

void	make_final(t_data *data, t_rc *rc)
{
	rc->h = (int)(HEIGHT / rc->dist);
	rc->starth = RESY / 2 - rc->h / 2;
	rc->endh = RESY / 2 + rc->h / 2;
	rc->dstx = rc->num;
	rc->dsty = 0;
	while (rc->dsty < RESY - 1)
	{
		if (rc->dsty < rc->starth + 1 / PTEX * rc->dist)
			cpy_color(&data->end, data->up_char, rc);
		else if (rc->starth <= rc->dsty && rc->dsty < rc->endh)
		{
			if (rc->what_wall == 'n')
				cpy_pixel(&data->end, &data->north, rc);
			if (rc->what_wall == 's')
				cpy_pixel(&data->end, &data->south, rc);
			if (rc->what_wall == 'e')
				cpy_pixel(&data->end, &data->east, rc);
			if (rc->what_wall == 'w')
				cpy_pixel(&data->end, &data->west, rc);
		}
		else if (rc->endh <= rc->dsty)
			cpy_color(&data->end, data->down_char, rc);
		rc->dsty++;
	}
}

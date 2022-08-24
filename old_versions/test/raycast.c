/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/14 00:48:28 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

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
	raycast3(data, r);
	raycast4(data, r);
	raycast5(data, r);
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

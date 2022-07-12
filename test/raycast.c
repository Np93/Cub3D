/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/12 04:20:15 by rmonney          ###   ########.fr       */
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

//1920rayons
void	raycast(t_data *data)
{
	t_rc	rc;

	rc.num = 0;
	rc.b = 0.96;
	rc.x = 0;
	while (rc.b >= -0.96)
	{
		collipov(data, &rc, data->look + rc.b, 0);
		make_final(data, &rc);
		rc.b -= 0.001;
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
	rc->num++;
}

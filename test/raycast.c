/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/07 19:00:58 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	raycast_test(t_data *data)
{
	t_rc	rc;
	t_tex	end;

	end.img = malloc(128 * 128 * 4);
	end.img = mlx_new_image(end.img, 128, 128);
	end.data_addr = mlx_get_data_addr(end.img, &end.bpp,
			&end.size_line, &end.endian);

	rc.ratio = 2;
	rc.dsty = 0;
	rc.srcy = 0;
	while (rc.srcy < 64)
	{
		rc.i = 1;
		while (rc.i <= rc.ratio)
		{
			rc.dstx = 20;
			rc.texx = 20;
			while (rc.texx < 40)
			{
				cpy_pixel(&end, &data->north, &rc);
				rc.texx++;
				rc.dstx++;
			}
			rc.dsty++;
			rc.i++;
		}
		rc.srcy++;
	}
	mlx_put_image_to_window(data->mlx, data->win, end.img, 800, 100);
	free(end.img);
}

void	cpy_pixel(t_tex *dst, t_tex *src, t_rc *rc)
{
	int	i;

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

void	raycast(t_data *data)
{
	t_rc	rc;

	rc.num = 0;
	rc.b = 0.96; // 1920rayons
	rc.x = 0;
	while (rc.b >= -0.96)
	{
		collipov(data, &rc, data->look + rc.b, 0);
//		what_hit(&rc);
		make_final(data, &rc);
		rc.b -= 0.001;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->end.img, 0, 0);
	clear_end(data);
}

void	make_final(t_data *data, t_rc *rc)
{
	rc->h = (int)(HEIGHT / rc->dist);
	rc->starth = RESY / 2 + rc->h / 2;
	if (rc->starth > RESY)
		rc->starth = RESY;
	rc->endh = RESY / 2 - rc->h / 2;

//	rc->srcy = 500;
	rc->dsty = rc->starth;
//	while (rc->srcy < 500 + rc->height)
	while (rc->dsty >= rc->endh && rc->dsty >= 0)
	{
		rc->dstx = rc->num * 1;
		while (rc->dstx < (rc->num + 1) * 1)
		{
			if (rc->what_wall == 'n')
				cpy_color(&data->end, data->up_char, rc);
				//cpy_pixel(&data->end, &data->north, rc);
			if (rc->what_wall == 's')
				cpy_color(&data->end, data->up_char, rc);
				//cpy_pixel(&data->end, &data->south, rc);
			if (rc->what_wall == 'e')
				cpy_color(&data->end, data->down_char, rc);
				//cpy_pixel(&data->end, &data->east, rc);
			if (rc->what_wall == 'w')
				cpy_color(&data->end, data->down_char, rc);
				//cpy_pixel(&data->end, &data->west, rc);
			rc->dstx++;
		}
	//	rc->dsty++;
		rc->dsty--;
		rc->srcy++;
	}
	rc->num++;
}

void	clear_end(t_data *data)
{
	int	x;

	x = 0;
	while (x < RESX * RESY * 4)
		data->end.data_addr[x++] = 0;

}

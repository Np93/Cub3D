/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/07 04:36:41 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	raycast_test(t_data *data)
{
	t_rc	rc;
	t_tex	end;

	end.img = malloc(128 * 128 * 4);
	end.img = mlx_new_image(end.img, 128, 128);
	end.data_addr = mlx_get_data_addr(end.img, &end.bpp, &end.size_line, &end.endian);

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
	rc.b = 0.96; // 191rayons
	rc.x = 0;
	while (rc.b >= -0.95)
	{
		collipov(data, &rc, data->look + rc.b, 0);
//		what_hit(&rc);
		make_final(data, &rc);
		rc.b -= 0.01;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->end.img, 0, 0);
}

void	make_final(t_data *data, t_rc *rc)
{
	rc->ratio = rc->dist;
	rc->srcy = 0;
	rc->dsty = 500;

	while (rc->srcy < 64)
	{
		rc->i = 1;
		while (rc->i <= rc->ratio)
		{
			rc->dstx = rc->num * 10;
			while (rc->dstx < (rc->num + 1) * 10)
			{
				if (rc->what_wall == 'n')
					cpy_pixel(&data->end, &data->north, rc);
				if (rc->what_wall == 's')
					cpy_pixel(&data->end, &data->south, rc);
				if (rc->what_wall == 'e')
					cpy_pixel(&data->end, &data->east, rc);
				if (rc->what_wall == 'w')
					cpy_pixel(&data->end, &data->west, rc);
				rc->dstx++;
			}
			rc->dsty++;
			rc->i += 1;
		}
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

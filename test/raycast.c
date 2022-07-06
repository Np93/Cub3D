/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/06 21:02:06 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	raycast_test(t_data *data)
{
	t_ray	ray;

	ray.dst.img = malloc(128 * 128 * 4);
	ray.dst.img = mlx_new_image(ray.dst.img, 128, 128);
	ray.dst.data_addr = mlx_get_data_addr(ray.dst.img, &ray.dst.bpp,
			&ray.dst.size_line, &ray.dst.endian);

	ray.src.data_addr = mlx_get_data_addr(data->north.img, &ray.src.bpp,
			&ray.src.size_line, &ray.src.endian);

	ray.ratio = 2;
	ray.dsty = 0;
	ray.srcy = 0;
	while (ray.srcy < 64)
	{
		ray.i = 1;
		while (ray.i <= ray.ratio)
		{
			ray.dstx = 20;
			ray.srcx = 20;
			while (ray.srcx <= 40)
			{
				cpy_pixel(&ray);
				ray.dstx++;
				ray.srcx++;
			}
			ray.dsty++;
			ray.i += 1;
		}
		ray.srcy++;
	}
	mlx_put_image_to_window(data->mlx, data->win, ray.dst.img, 350, 350);
	free(ray.dst.img);
}

void	cpy_pixel(t_ray *ray)
{
	int	i;

	i = -1;
	while (++i <= 3)
		ray->dst.data_addr[(4 * ray->dstx) + (ray->dsty
				* ray->dst.size_line) + i]
			= ray->src.data_addr[(4 * ray->srcx)
			+ (ray->srcy * ray->src.size_line) + i];
}

// ATTENTION SENS ANTIHORAIRE CAUSE CERCLE TRIGO //
void	what_hit(t_rc *rc, float angle)
{
	if (rc->side == 0)
	{
		if (PI / 2 <= angle && angle <= 3 * PI / 2)
			printf("ray[%d] hit wall EAST ", rc->num);
		else
			printf("ray[%d] hit wall WEST ", rc->num);
	}
	else
	{
		if (0 <= angle && angle <= PI)
			printf("ray[%d] hit wall SOUTH ", rc->num);
		else
			printf("ray[%d] hit wall NORTH ", rc->num);
	}
	printf("at dist = [%f], wallx = [%f] & texx = [%d]\n",
		rc->dist, rc->wallx, rc->texx);
	rc->num++;
	if (rc->num == 101)
		printf("\n\n");
}

void	raycast(t_data *data)
{
	t_rc	rc;

	rc.num = 1;
	rc.b = -0.99; // 100rayons
	rc.x = 0;
	while (rc.b <= 0.99)
	{
		collipov(data, &rc, data->look + rc.b, 0);
		what_hit(&rc, data->look + rc.b);
		rc.b += 0.02;
	}
}

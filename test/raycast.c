/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/05 21:04:00 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	my_mlx_pixel_put(t_tex *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	raycast(t_data *data)
{
	t_ray	ray;

	ray.dst.img = malloc(RESX * RESY * 4);
	ray.dst.img = mlx_new_image(ray.dst.img, 128, 128);
	ray.dst.data_addr = mlx_get_data_addr(ray.dst.img, &ray.dst.bpp,
			&ray.dst.size_line, &ray.dst.endian);

	ray.src.data_addr = mlx_get_data_addr(data->south.img, &ray.src.bpp,
			&ray.src.size_line, &ray.src.endian);

	ray.ratio = 2;
	ray.dsty = 0;
	ray.srcy = 0;
	while (ray.srcy <= 64)
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

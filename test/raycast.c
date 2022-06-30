/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:54:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/30 22:49:07 by rmonney          ###   ########.fr       */
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
	t_tex	img;
	t_tex	wimg;

	img.img = malloc(RESX * RESY * 4);
	img.img = mlx_new_image(img.img, 64, 64);
	img.data_addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.size_line, &img.endian);

	wimg.data_addr = mlx_get_data_addr(data->south.img, &wimg.bpp,
			&wimg.size_line, &wimg.endian);
	int	x;
	int	y;

	y = 0;
	while (0 <= y && y <= 64 * 64 * 4)
	{
		x = 1 * 4;
		while (x <= 2 * 4)
		{
			img.data_addr[x * 4 + y * data->south.size_line * 4]
				= wimg.data_addr[x * 4 + y * data->south.size_line * 4];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img.img, 350, 350);
}

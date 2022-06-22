/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 21:01:42 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	green_pix_maker(t_data *data)
{
	int	x;
	int	y;

	data->green_pix = mlx_new_image(data->mlx, 3, 3);
	data->addr_g = mlx_get_data_addr(data->green_pix, &data->bpp_g,
			&data->line_length_g, &data->endian_g);
	if (!data->addr_g)
		error_handle(6);
	x = -1;
	while (++x <= 3)
	{
		y = -1;
		while (++y <= 3)
			my_mlx_pixel_put(data, x, y, 0x0000FF00);
	}
}

void	red_pix_maker(t_data *data)
{
	int	x;
	int	y;

	data->red_pix = mlx_new_image(data->mlx, 2, 2);
	data->addr_r = mlx_get_data_addr(data->red_pix, &data->bpp_r,
			&data->line_length_r, &data->endian_r);
	if (!data->addr_r)
		error_handle(6);
	x = -1;
	while (++x <= 2)
	{
		y = -1;
		while (++y <= 2)
			my_mlx_pixel_put(data, x, y, 0x00FF0000);
	}

}

void	mlx_initer(t_data *data)
{
	int	x;

	x = 0;
	data->mlx = mlx_init();
	data->win_m = mlx_new_window(data->mlx, data->map_xsize * PMAP,
			data->map_ysize * PMAP, "minimap");
//	data->win_g = mlx_new_window(data->mlx, 1920, 1080, "cub3D");
	data->w_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/g40.xpm", &x, &x);
	data->f_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/b40.xpm", &x, &x);
	if (!data->w_mmap || !data->f_mmap)
		error_handle(6);
	red_pix_maker(data);
	green_pix_maker(data);
}

void	start(t_data *data)
{
	mlx_initer(data);
	print_minimap(data);
	mlx_hook(data->win_m, 2, 1L << 1, deal_key, data);
	mlx_hook(data->win_m, 17, 0, exiter, NULL);
	mlx_loop(data->mlx);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/21 18:46:10 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	mlx_initer(t_data *data)
{
	int	x;

	x = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_xsize * 50,
		data->map_ysize * 50, "minimmap");
	data->w_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/g50.xpm", &x, &x);
	data->f_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/b50.xpm", &x, &x);
	data->p_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/r10.xpm", &x, &x);
	data->red_pix = mlx_new_image(data->mlx, 1, 1);
	data->addr = mlx_get_data_addr(data->red_pix, &data->bpp, &data->line_length,
		&data->endian);
	my_mlx_pixel_put(data, 0, 0, 0x00FF00CC);
}

void	start(t_data *data)
{
	mlx_initer(data);
	print_minimap(data);
	mlx_key_hook(data->win, deal_key, data);
	mlx_hook(data->win, 17, 0, exiter, NULL);
	mlx_do_key_autorepeaton(data->mlx);   // ?
	mlx_loop(data->mlx);
	return ;
}

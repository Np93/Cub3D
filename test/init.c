/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 22:36:45 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

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
	data->red_pix = mlx_xpm_file_to_image(data->mlx, "sprites/r2.xpm", &x, &x);
	data->red_big = mlx_xpm_file_to_image(data->mlx, "sprites/r3.xpm", &x, &x);
	data->red_max = mlx_xpm_file_to_image(data->mlx, "sprites/r4.xpm", &x, &x);
	data->green_pix = mlx_xpm_file_to_image(data->mlx,
			"sprites/g3.xpm", &x, &x);
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

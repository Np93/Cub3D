/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/28 21:35:44 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	mlx_initer(t_data *data)
{
	int	x;

	x = 0;
	data->mlx = mlx_init();
//	data->win_m = mlx_new_window(data->mlx, data->map_xsize * PMAP,
//			data->map_ysize * PMAP, "minimap");
//	data->win_m = mlx_new_window(data->mlx, 9 * PMAP, 9 * PMAP, "map");
	data->win_m = mlx_new_window(data->mlx, 1920, 1080, "cub3D");
	data->w_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/g30.xpm", &x, &x);
	data->f_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/b30.xpm", &x, &x);
	data->red_pix = mlx_xpm_file_to_image(data->mlx, "sprites/r1.xpm", &x, &x);
//	data->red_pix = mlx_xpm_file_to_image(data->mlx, "sprites/r3.xpm", &x, &x);
	data->red_big = mlx_xpm_file_to_image(data->mlx, "sprites/r4.xpm", &x, &x);
	data->red_max = mlx_xpm_file_to_image(data->mlx, "sprites/r6.xpm", &x, &x);
	data->green_pix = mlx_xpm_file_to_image(data->mlx,
			"sprites/g4.xpm", &x, &x);
	data->steel = mlx_xpm_file_to_image(data->mlx, "sprites/steel330.xpm", &x, &x);
}

void	start(t_data *data)
{
	mlx_initer(data);
	data->first_x = data->pos_x;
	data->first_y = data->pos_y;
	print_minimap(data);
	mlx_hook(data->win_m, 2, 1L << 1, deal_key, data);
	mlx_hook(data->win_m, 17, 0, exiter, NULL);
	mlx_loop(data->mlx);
	return ;
}

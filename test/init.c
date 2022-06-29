/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/29 22:26:43 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"
//res en 2080x1170 ?//

void	mlx_initer(t_data *data)
{
	int	x;

	x = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 330, 330, "cub3D");
	data->w_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/g30.xpm", &x, &x);
	data->f_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/b30.xpm", &x, &x);
	data->red_pix = mlx_xpm_file_to_image(data->mlx, "sprites/r1.xpm", &x, &x);
	data->green_pix = mlx_xpm_file_to_image(data->mlx,
			"sprites/g4.xpm", &x, &x);
	data->map_frame = mlx_xpm_file_to_image(data->mlx,
			"sprites/steel330_crop.xpm", &x, &x);
}

void	start(t_data *data)
{
	mlx_initer(data);
	print_minimap(data);
	mlx_hook(data->win, 2, 1L << 1, deal_key, data);
	mlx_hook(data->win, 17, 0, exiter, NULL);
	mlx_loop(data->mlx);
	return ;
}

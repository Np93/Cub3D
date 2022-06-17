/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/17 17:37:46 by rmonney          ###   ########.fr       */
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
}

void	start(t_data *data)
{
	(void)data;
	return ;
}

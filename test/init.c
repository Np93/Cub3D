/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/30 22:34:25 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"
//res en 2080x1170 ?//

void	tex_init(t_data *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx, "sprites/WN.xpm",
			&data->north.x, &data->north.y);
	data->north.data_addr = mlx_get_data_addr(data->north.img,
			&data->north.bpp, &data->north.size_line, &data->north.endian);
	data->south.img = mlx_xpm_file_to_image(data->mlx, "sprites/WS.xpm",
			&data->south.x, &data->south.y);
	data->south.data_addr = mlx_get_data_addr(data->south.img,
			&data->south.bpp, &data->south.size_line, &data->south.endian);
	data->east.img = mlx_xpm_file_to_image(data->mlx, "sprites/WE.xpm",
			&data->east.x, &data->east.y);
	data->east.data_addr = mlx_get_data_addr(data->east.img,
			&data->east.bpp, &data->east.size_line, &data->east.endian);
	data->west.img = mlx_xpm_file_to_image(data->mlx, "sprites/WW.xpm",
			&data->west.x, &data->west.y);
	data->west.data_addr = mlx_get_data_addr(data->west.img,
			&data->west.bpp, &data->west.size_line, &data->west.endian);
}

void	mlx_initer(t_data *data)
{
	int	x;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 600, "cub3D");
	data->w_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/g30.xpm", &x, &x);
	data->f_mmap = mlx_xpm_file_to_image(data->mlx, "sprites/b30.xpm", &x, &x);
	data->red_pix = mlx_xpm_file_to_image(data->mlx, "sprites/r1.xpm", &x, &x);
	data->green_pix = mlx_xpm_file_to_image(data->mlx,
			"sprites/g4.xpm", &x, &x);
	data->map_frame = mlx_xpm_file_to_image(data->mlx,
			"sprites/steel330_crop.xpm", &x, &x);
	tex_init(data);
	data->move = 0.1;
	data->pov = 0.1;
	data->which_key = -1;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/05 21:47:45 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"
//res en 2080x1170 ?//

void	init_up_down(t_data *data)
{
	int	x;

///// initie dans le parsing ///
	data->down_int[0] = 0;
	data->down_int[1] = 220;
	data->down_int[2] = 120;
	data->up_int[0] = 0;
	data->up_int[1] = 20;
	data->up_int[2] = 240;
///////////////////////
	data->up.img = malloc(RESX * (RESY / 2) * 4);
	data->down.img = malloc(RESX * (RESY / 2) * 4);
	if (!data->up.img || !data->down.img)
		error_handle(5);
	data->up.img = mlx_new_image(data->up.img, RESX, RESY / 2);
	data->down.img = mlx_new_image(data->down.img, RESX, RESY / 2);
	data->up.data_addr = mlx_get_data_addr(data->up.img, &data->up.bpp,
			&data->up.size_line, &data->up.endian);
	data->down.data_addr = mlx_get_data_addr(data->down.img, &data->down.bpp,
			&data->down.size_line, &data->down.endian);
	x = 0;
	while (x <= RESX * RESY / 2 * 4)
	{
		data->down.data_addr[x++] = data->down_int[0];
		data->down.data_addr[x++] = data->down_int[1];
		data->down.data_addr[x++] = data->down_int[2];
		x++;
	}
	x = 0;
	while (x <= RESX * RESY / 2 * 4)
	{
		data->up.data_addr[x++] = data->up_int[0];
		data->up.data_addr[x++] = data->up_int[1];
		data->up.data_addr[x++] = data->up_int[2];
		x++;
	}
}

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
	init_up_down(data);
}

void	mlx_initer(t_data *data)
{
	int	x;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, RESX, RESY, "cub3D");
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
	mlx_put_image_to_window(data->mlx, data->win, data->up.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->down.img, 0, RESY / 2);
	print_minimap(data);
	mlx_hook(data->win, 2, 1L << 1, deal_key, data);
	mlx_hook(data->win, 17, 0, exiter, NULL);
	mlx_loop(data->mlx);
	return ;
}

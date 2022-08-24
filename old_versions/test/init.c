/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:15 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 02:02:24 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"
//res en 2080x1170 ?//

void	tex_init2(t_data *data)
{
	int	x;
	int	y;

	data->up_char[0] = data->up_int[0];
	data->up_char[1] = data->up_int[1];
	data->up_char[2] = data->up_int[2];
	data->down_char[0] = data->down_int[0];
	data->down_char[1] = data->down_int[1];
	data->down_char[2] = data->down_int[2];
	x = 0;
	while (x < RESX)
	{
		y = 0;
		while (y < RESY)
		{
			data->w.data_addr[4 * x + data->w.size_line * y] = (char)255;
			data->w.data_addr[4 * x + data->w.size_line * y + 1] = (char)255;
			data->w.data_addr[4 * x + data->w.size_line * y + 2] = (char)255;
			data->w.data_addr[4 * x + data->w.size_line * y + 3] = (char)150;
			y++;
		}
		x++;
	}
}

void	tex_init(t_data *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx, data->path_n,
			&data->north.x, &data->north.y);
	data->north.data_addr = mlx_get_data_addr(data->north.img,
			&data->north.bpp, &data->north.size_line, &data->north.endian);
	data->south.img = mlx_xpm_file_to_image(data->mlx, data->path_s,
			&data->south.x, &data->south.y);
	data->south.data_addr = mlx_get_data_addr(data->south.img,
			&data->south.bpp, &data->south.size_line, &data->south.endian);
	data->east.img = mlx_xpm_file_to_image(data->mlx, data->path_e,
			&data->east.x, &data->east.y);
	data->east.data_addr = mlx_get_data_addr(data->east.img,
			&data->east.bpp, &data->east.size_line, &data->east.endian);
	data->west.img = mlx_xpm_file_to_image(data->mlx, data->path_w,
			&data->west.x, &data->west.y);
	data->west.data_addr = mlx_get_data_addr(data->west.img,
			&data->west.bpp, &data->west.size_line, &data->west.endian);
	data->end.img = malloc(RESX * RESY * 4);
	data->end.img = mlx_new_image(data->end.img, RESX, RESY);
	data->end.data_addr = mlx_get_data_addr(data->end.img, &data->end.bpp,
			&data->end.size_line, &data->end.endian);
	data->w.img = malloc(RESX * RESY * 4);
	data->w.img = mlx_new_image(data->w.img, RESX, RESY);
	data->w.data_addr = mlx_get_data_addr(data->w.img, &data->w.bpp,
			&data->w.size_line, &data->w.endian);
	tex_init2(data);
}

void	set_ray(t_data *data)
{
	if (data->init_dir == 'e')
	{
		data->planex = 0;
		data->planey = 0.66;
		data->dirx = 1;
		data->diry = 0;
	}
	if (data->init_dir == 'n')
	{
		data->planex = 0.66;
		data->planey = 0;
		data->dirx = 0;
		data->diry = -1;
	}
	set_ray2(data);
}

void	set_ray2(t_data *data)
{
	if (data->init_dir == 'w')
	{
		data->planex = 0;
		data->planey = -0.66;
		data->dirx = -1;
		data->diry = 0;
	}
	if (data->init_dir == 's')
	{
		data->planex = -0.66;
		data->planey = 0;
		data->dirx = 0;
		data->diry = 1;
	}
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
	data->fps1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/360fps1.xpm", &x, &x);
	data->fps2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/360fps2.xpm", &x, &x);
	data->cross1 = mlx_xpm_file_to_image(data->mlx,
			"sprites/cross1s.xpm", &x, &x);
	data->cross2 = mlx_xpm_file_to_image(data->mlx,
			"sprites/cross2s.xpm", &x, &x);
	tex_init(data);
	data->move = 0.1;
	data->pov_divider = 50;
	data->pov = PI / data->pov_divider;
	data->which_key = -1;
	data->cross = 1;
}

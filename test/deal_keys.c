/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:11:09 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/30 02:57:23 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	key_pov(t_data *data, int key)
{
	if (key == 123)
		data->look += POV;
	else if (key == 124)
		data->look -= POV;
	if (data->look < 0)
		data->look = (PI * 2);
	else if (data->look > (PI * 2))
		data->look = 0;
}

void	colliwall2(int key, t_data *data, float *next_x, float *next_y)
{
	if (key == 13)
	{
		*next_x += cos(data->look) * MOVE;
		*next_y -= sin(data->look) * MOVE;
	}
	else if (key == 0)
	{
		*next_x -= sin(data->look) * MOVE;
		*next_y -= cos(data->look) * MOVE;
	}
	else if (key == 1)
	{
		*next_x -= cos(data->look) * MOVE;
		*next_y += sin(data->look) * MOVE;
	}
	else if (key == 2)
	{
		*next_x += sin(data->look) * MOVE;
		*next_y += cos(data->look) * MOVE;
	}
}

void	colliwall(int key, t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->pos_x;
	next_y = data->pos_y;
	data->x_ok = 1;
	data->y_ok = 1;
	colliwall2(key, data, &next_x, &next_y);
	if (data->map[(int)(data->pos_y)][(int)(next_x)] == '1')
		data->x_ok = 0;
	if (data->map[(int)(next_y)][(int)(data->pos_x)] == '1')
		data->y_ok = 0;
	if (data->map[(int)(next_y)][(int)(next_x)] == '1'
			&& data->x_ok && data->y_ok)
	{
		data->x_ok = 0;
		data->y_ok = 0;
	}
}

void	deal_key2(int key, t_data *data)
{
	if (data->x_ok)
	{
		if (key == 13)
			data->pos_x += cos(data->look) * MOVE;
		else if (key == 0)
			data->pos_x -= sin(data->look) * MOVE;
		else if (key == 1)
			data->pos_x -= cos(data->look) * MOVE;
		else if (key == 2)
			data->pos_x += sin(data->look) * MOVE;
	}
	if (data->y_ok)
	{
		if (key == 13)
			data->pos_y -= sin(data->look) * MOVE;
		else if (key == 0)
			data->pos_y -= cos(data->look) * MOVE;
		else if (key == 1)
			data->pos_y += sin(data->look) * MOVE;
		else if (key == 2)
			data->pos_y += cos(data->look) * MOVE;
	}
}

////////////// tentative de choper un bout de texture et l'afficher ensuite ///////////////

void	my_mlx_pixel_put(t_ray_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data_addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	test_img(t_data *data)
{
	t_ray_img	img;
	t_ray_img	wimg;
	int			x;

	x = 0;
	img.data_addr = malloc(sizeof(char) * 999999999);
	img.img_ptr = malloc(99999999999);
	img.img_ptr = mlx_new_image(img.img_ptr, 30, 30);
	img.data_addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);


	wimg.data_addr = malloc(sizeof(char) * 999999999);
	wimg.img_ptr = mlx_xpm_file_to_image(data->mlx, "sprites/g30.xpm", &x, &x);
	wimg.data_addr = mlx_get_data_addr(wimg.img_ptr, &wimg.bpp, &wimg.size_line, &wimg.endian);
	

	while (x < 1500)
	{
		img.data_addr[x] = wimg.data_addr[x];
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img.img_ptr, 350, 350);
}

//////////////////////////////////////////////////////////////////////////////////////////

int	deal_key(int key, t_data *data)
{
	colliwall(key, data);
	deal_key2(key, data);
	if (key == 53)
		exiter();
	if (key == 123 || key == 124)
		key_pov(data, key);
	mlx_clear_window(data->mlx, data->win);
	print_minimap(data);
	if (key == 7)
		mlx_clear_window(data->mlx, data->win);
	if (key == 45)
		test_img(data);
	return (0);
}

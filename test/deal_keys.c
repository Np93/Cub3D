/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:11:09 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/07 18:50:23 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	key_pov(t_data *data, int key)
{
	if (key == 123)
		data->look += data->pov;
	else if (key == 124)
		data->look -= data->pov;
	if (data->look < 0)
		data->look += PI * 2;
	else if (data->look > (PI * 2))
		data->look -= PI * 2;
}

void	colliwall2(int key, t_data *data, float *next_x, float *next_y)
{
	if (key == 13)
	{
		*next_x += cos(data->look) * data->move;
		*next_y -= sin(data->look) * data->move;
	}
	else if (key == 0)
	{
		*next_x -= sin(data->look) * data->move;
		*next_y -= cos(data->look) * data->move;
	}
	else if (key == 1)
	{
		*next_x -= cos(data->look) * data->move;
		*next_y += sin(data->look) * data->move;
	}
	else if (key == 2)
	{
		*next_x += sin(data->look) * data->move;
		*next_y += cos(data->look) * data->move;
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
			data->pos_x += cos(data->look) * data->move;
		else if (key == 0)
			data->pos_x -= sin(data->look) * data->move;
		else if (key == 1)
			data->pos_x -= cos(data->look) * data->move;
		else if (key == 2)
			data->pos_x += sin(data->look) * data->move;
	}
	if (data->y_ok)
	{
		if (key == 13)
			data->pos_y -= sin(data->look) * data->move;
		else if (key == 0)
			data->pos_y -= cos(data->look) * data->move;
		else if (key == 1)
			data->pos_y += sin(data->look) * data->move;
		else if (key == 2)
			data->pos_y += cos(data->look) * data->move;
	}
}

int	deal_key(int key, t_data *data)
{
	colliwall(key, data);
	deal_key2(key, data);
	if (key == 53)
		exiter();
	if (key == 123 || key == 124)
		key_pov(data, key);
	settings_keys(key, data);
	mlx_clear_window(data->mlx, data->win);
	raycast(data);
//	mlx_put_image_to_window(data->mlx, data->win, data->north.img, 700, 100);
	print_minimap(data);
	if (key == 7)
		mlx_clear_window(data->mlx, data->win);
	if (key == 45)
		raycast_test(data);
	return (0);
}

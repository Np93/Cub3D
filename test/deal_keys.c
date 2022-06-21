/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:11:09 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/21 18:52:16 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	key_pov(t_data *data, int key)
{
	if (key == 123)
		data->look += 0.1;
	else if (key == 124)
		data->look -= 0.1;
	if (data->look < 0)
		data->look = (M_PI * 2);
	else if (data->look > (M_PI * 2))
		data->look = 0;
}

int	colliwall(int key, t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->pos_x;
	next_y = data->pos_y;
	if (key == 	13)
			next_y -= 0.1;
	else if (key == 0)
			next_x -= 0.1;
	else if (key == 1)
			next_y += 0.1;
	else if (key == 2)
			next_x += 0.1;
	if (data->map[(int)(next_y)][(int)(next_x)] == '1')
		return (1);
	return (0);
}

int	deal_key(int key, t_data *data)
{
	if (!colliwall(key, data))
	{
		if (key == 	13)
			data->pos_y -= 0.1;
		else if (key == 0)
			data->pos_x -= 0.1;
		else if (key == 1)
			data->pos_y += 0.1;
		else if (key == 2)
			data->pos_x += 0.1;
	}
	if (key == 53)
		exiter();
	if (key == 123 || key == 124)
		key_pov(data, key);
	mlx_clear_window(data->mlx, data->win);
	print_minimap(data);
	if (key == 7)
		mlx_clear_window(data->mlx, data->win);
	return (0);
}

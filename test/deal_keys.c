/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:11:09 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 19:32:14 by rmonney          ###   ########.fr       */
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

int	colliwall(int key, t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->pos_x;
	next_y = data->pos_y;
	if (key == 13)
			next_y -= MOVE;
	else if (key == 0)
			next_x -= MOVE;
	else if (key == 1)
			next_y += MOVE;
	else if (key == 2)
			next_x += MOVE;
	if (data->map[(int)(next_y)][(int)(next_x)] == '1')
		return (1);
	return (0);
}

int	deal_key(int key, t_data *data)
{
	if (!colliwall(key, data))
	{
		if (key == 13)
			data->pos_y -= MOVE;
		else if (key == 0)
			data->pos_x -= MOVE;
		else if (key == 1)
			data->pos_y += MOVE;
		else if (key == 2)
			data->pos_x += MOVE;
	}
	if (key == 53)
		exiter();
	if (key == 123 || key == 124)
		key_pov(data, key);
	mlx_clear_window(data->mlx, data->win_m);
	print_minimap(data);
	if (key == 7)
		mlx_clear_window(data->mlx, data->win_m);
	return (0);
}

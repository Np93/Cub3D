/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:59:16 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/13 23:32:38 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	settings_keys2(int key, t_data *data)
{
	if (key == 69 && data->move < 0.46)
	{
		data->move += 0.05;
		printf("PLAYER SPEED = [%d]\n", (int)(data->move / 0.05));
	}
	if (key == 78 && 0.06 < data->move)
	{
		data->move -= 0.05;
		printf("PLAYER SPEED = [%d]\n", (int)(data->move / 0.05));
	}
}

void	settings_keys(int key, t_data *data)
{
	if (0 < data->which_key)
		printf("key pressed = [%d]\n", key);
	if (key == 40)
	{
		if (data->which_key < 0)
			printf("WHICH KEY MODE ENABLED\n");
		else
			printf("WHICH KEY MODE DISABLED\n");
		data->which_key *= -1;
	}
	settings_keys2(key, data);
}

void	shoot(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->white.img, 0, 0);
	print_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fps2, 780, 720);
	mlx_do_sync(data->mlx);
	raycast(data);
	print_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fps1, 780, 720);
}

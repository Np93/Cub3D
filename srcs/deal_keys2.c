/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:59:16 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 22:44:07 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

void	settings_keys3(int key, t_data *data)
{
	if (key == 126 && 20 < data->pov_divider)
	{
		data->pov_divider -= 10;
		data->pov = PI / data->pov_divider;
		data->pov_speed[13]++;
		set_ray(data);
	}
	if (key == 125 && data->pov_divider < 50)
	{
		data->pov_divider += 10;
		data->pov = PI / data->pov_divider;
		data->pov_speed[13]--;
		set_ray(data);
	}
}

void	settings_keys2(int key, t_data *data)
{
	if (key == 69 && data->move < 0.39)
	{
		data->move += 0.1;
		data->move_speed[16]++;
	}
	if (key == 78 && 0.11 < data->move)
	{
		data->move -= 0.1;
		data->move_speed[16]--;
	}
	settings_keys3(key, data);
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
	mlx_put_image_to_window(data->mlx, data->win, data->w.img, 0, 0);
	if (0 < data->cross)
		mlx_put_image_to_window(data->mlx, data->win, data->cross2, 935, 515);
	print_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fps2, 780, 720);
	mlx_do_sync(data->mlx);
	raycast(data);
	print_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fps1, 780, 720);
}

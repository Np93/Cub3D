/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:59:16 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/13 06:03:43 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	settings_keys2(int key, t_data *data)
{
	if (key == 69 && data->move < 0.95)
	{
		data->move += 0.1;
		printf("PLAYER SPEED = [%f]\n", data->move);
	}
	if (key == 78 && 0.15 < data->move)
	{
		data->move -= 0.1;
		printf("PLAYER SPEED = [%f]\n", data->move);
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
/*	if (key == 126 && data->pov < 0.95)
	{
		data->pov += 0.1;
		data->rotspeed += 0.1;
		printf("POV SPEED = [%f]\n", data->pov);
	}
	if (key == 125 && 0.15 < data->pov)
	{
		data->pov -= 0.1;
		data->rotspeed -= 0.1;
		printf("POV SPEED = [%f]\n", data->pov);
	}*/
	settings_keys2(key, data);
}

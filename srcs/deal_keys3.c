/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:15:30 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 22:44:15 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

void	values_correction(t_data *data)
{
	if (0.95 <= data->dirx && data->dirx <= 1.05
		&& -0.05 <= data->diry && data->diry <= 0.05)
	{
		data->dirx = 1;
		data->diry = 0;
		data->planex = 0;
		data->planey = 0.66;
		data->look = 0;
	}
	if (-1.05 <= data->dirx && data->dirx <= -0.95
		&& -0.05 <= data->diry && data->diry <= 0.05)
	{
		data->dirx = -1;
		data->diry = 0;
		data->planex = 0;
		data->planey = -0.66;
		data->look = PI;
	}
	values_correction2(data);
}

void	values_correction2(t_data *data)
{
	if (-0.05 <= data->dirx && data->dirx <= 0.05
		&& 0.99 <= data->diry && data->diry <= 1.01)
	{
		data->dirx = 0;
		data->diry = 1;
		data->planex = -0.66;
		data->planey = 0;
		data->look = 3 * PI / 2;
	}
	if (-0.05 <= data->dirx && data->dirx <= 0.05
		&& -1.05 <= data->diry && data->diry <= -0.95)
	{
		data->dirx = 0;
		data->diry = -1;
		data->planex = 0.66;
		data->planey = 0;
		data->look = PI / 2;
	}
}

void	key_pov(t_data *data, int key)
{
	if (key == 123)
	{
		data->look += data->pov;
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(-data->pov)
			- data->diry * sin(-data->pov);
		data->diry = data->olddirx * sin(-data->pov)
			+ data->diry * cos(-data->pov);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(-data->pov)
			- data->planey * sin(-data->pov);
		data->planey = data->planex * sin(-data->pov)
			+ data->planey * cos(-data->pov);
	}
	key_pov2(data, key);
}

void	key_pov2(t_data *data, int key)
{
	if (key == 124)
	{
		data->look -= data->pov;
		data->olddirx = data->dirx;
		data->dirx = data->dirx * cos(data->pov)
			- data->diry * sin(data->pov);
		data->diry = data->olddirx * sin(data->pov)
			+ data->diry * cos(data->pov);
		data->oldplanex = data->planex;
		data->planex = data->planex * cos(data->pov)
			- data->planey * sin(data->pov);
		data->planey = data->planex * sin(data->pov)
			+ data->planey * cos(data->pov);
	}
	if (data->look < 0)
		data->look += PI * 2;
	else if (data->look > (PI * 2))
		data->look -= PI * 2;
}

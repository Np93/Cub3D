/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:32:43 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/23 00:02:05 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

void	tex_init3(t_data *data)
{
	data->north.data_addr = mlx_get_data_addr(data->north.img,
			&data->north.bpp, &data->north.size_line, &data->north.endian);
	data->south.data_addr = mlx_get_data_addr(data->south.img,
			&data->south.bpp, &data->south.size_line, &data->south.endian);
	data->east.data_addr = mlx_get_data_addr(data->east.img,
			&data->east.bpp, &data->east.size_line, &data->east.endian);
	data->west.data_addr = mlx_get_data_addr(data->west.img,
			&data->west.bpp, &data->west.size_line, &data->west.endian);
}

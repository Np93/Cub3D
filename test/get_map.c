/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:56:39 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 19:32:41 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

char	**get_map(char *map_path)
{
	char	*tmp;
	int		fd;
	int		i;
	char	**ret;

	ret = malloc(sizeof(char *) * 999);
	if (!ret)
	{
		error_handle(5);
		return (NULL);
	}
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		else
			ret[i++] = ft_strdup(tmp);
		free(tmp);
	}
	ret[i] = NULL;
	return (ret);
}

void	get_angle_pov(t_data *data, char dir)
{
	if (dir == 'N')
		data->look = (PI / 2);
	else if (dir == 'S')
		data->look = ((PI * 3) / 2);
	else if (dir == 'E')
		data->look = 0;
	else if (dir == 'W')
		data->look = PI;
}

void	get_map_infos(t_data *data)
{
	int	x;
	int	y;

	data->map_xsize = ft_strlen(data->map[0]) - 1;//format de map rectanlge?
	y = -1;
	while (data->map[++y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				data->pos_x = (float)x + 0.5;
				data->pos_y = (float)y + 0.5;
				get_angle_pov(data, data->map[y][x]);
			}
			x++;
		}
	}
	data->map_ysize = y;
}

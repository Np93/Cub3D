/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:56:39 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 05:59:50 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

char	**get_map(char *map_path, int size)
{
	char	*tmp;
	int		fd;
	int		i;
	char	**ret;

	if (size <= 0)
		error_handle(5);
	ret = malloc(sizeof(char *) * (size + 1));
	if (!ret)
		error_handle(5);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_handle(4);
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
	{
		data->look = (PI / 2);
		data->init_dir = 'n';
	}
	else if (dir == 'S')
	{
		data->look = ((PI * 3) / 2);
		data->init_dir = 's';
	}
	else if (dir == 'E')
	{
		data->look = 0;
		data->init_dir = 'e';
	}
	else if (dir == 'W')
	{
		data->look = PI;
		data->init_dir = 'w';
	}
}

void	map_close(t_data *data, int y, int x, int count)
{
	if (data->map[y][0] == '0' || (data->map[y][x] == '0' && (count < x
		|| data->count_y == y))
		|| (data->map[y][x] == '0' && (data->map[y + 1][x] == ' '
		|| data->map[y - 1][x] == ' ' || data->map[y][x + 1] == ' '
		|| data->map[y][x - 1] == ' ' || data->map[y][x + 1] == '\n'
		|| data->map[y][x + 1] == '\0' || data->map[y + 1][x] == '\0'
		|| data->map[y - 1][x] == '\0' || data->map[y - 1][x] == '\n'
		|| data->map[y + 1][x] == '\n')))
		error_handle3(2);
	if ((data->map[y][x] == 'N' || data->map[y][x] == 'W'
		|| data->map[y][x] == 'S' || data->map[y][x] == 'E')
		&& (count < x || data->count_y == y || x == 0
		|| data->map[y + 1][x] == ' ' || data->map[y - 1][x] == ' '
		|| data->map[y][x + 1] == ' ' || data->map[y][x - 1] == ' '
		|| data->map[y][x + 1] == '\n' || data->map[y + 1][x] == '\n'
		|| data->map[y - 1][x] == '\n' || data->map[y][x + 1] == '\0'
		|| data->map[y + 1][x] == '\0' || data->map[y - 1][x] == '\0'))
		error_handle3(1);
}

void	get_map_info2(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
		|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
	{
		data->pos_x = (float)x + 0.5;
		data->pos_y = (float)y + 0.5;
		get_angle_pov(data, data->map[y][x]);
		data->player = ++(data->player);
	}
	if (data->map[y][x] != 'N' && data->map[y][x] != 'S'
		&& data->map[y][x] != 'E' && data->map[y][x] != 'W'
		&& data->map[y][x] != '1' && data->map[y][x] != '0'
		&& data->map[y][x] != ' ' && data->map[y][x] != '\n')
		error_handle3(0);
}

void	get_map_infos(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	count;

	i = 0;
	y = -1;
	count = 0;
	data->player = 0;
	while (data->map[++y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			get_map_info2(data, x, y);
			map_close(data, y, x, count);
			x++;
			if (i < x)
				i = x;
		}
		count = x;
	}
	data->map_xsize = (i - 1);
	data->map_ysize = y;
}

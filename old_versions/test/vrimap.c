/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrimap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:29:37 by nhirzel           #+#    #+#             */
/*   Updated: 2022/08/17 04:56:24 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

char	*ft_load_img(char *line, char *path)
{
	int	i;
	int	count;

	i = strlen(line);
	path = malloc(sizeof(char) * (i + 1));
	count = -1;
	while (line[i] != '.')
		i--;
	if (line[i] != '.' || line[i + 1] != 'x' || line[i + 2] != 'p'
		|| line[i + 3] != 'm')
		error_handle(7);
	i = (i - 1);
	while (line[i] != '.')
		i--;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			break ;
		path[++count] = line[i];
		i++;
	}
	path[count + 1] = '\0';
	if (path == NULL)
		error_handle(8);
	return (path);
}

char	*get_img(t_data *data, char *line, int count)
{
	int	i;

	i = 0;
	line[count + 1] = '\0';
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		data->path_n = ft_load_img(line, data->path_n);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		data->path_s = ft_load_img(line, data->path_s);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		data->path_w = ft_load_img(line, data->path_w);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		data->path_e = ft_load_img(line, data->path_e);
	else if (line[i] == 'C')
		ft_coolor_c(data, line);
	else if (line[i] == 'F')
		ft_coolor_f(data, line);
	i = strlen(line);
	while (i >= 0)
	{
		line[i] = '\0';
		i--;
	}
	return (line);
}

void	get_wall2(t_data *data, int y)
{
	if (data->path_n != NULL && data->path_s != NULL
		&& data->path_w != NULL && data->path_e != NULL
		&& data->up_int[0] == data->ref_up
		&& data->down_int[0] == data->ref_down)
	{
		if ((++(data->count)) == 1)
			data->count_y = y;
			data->rep = 0;
	}
}

void	get_wall1(t_data *data)
{
	int		x;
	int		y;
	char	*temp;
	int		i;

	y = -1;
	temp = malloc(sizeof(char) * 993);
	while (data->map_game[++y] != NULL)
	{
		get_wall2(data, y);
		x = -1;
		while (data->map_game[y][++x] != '\0')
		{
			if (data->map_game[y][x] == 'N' || data->map_game[y][x] == 'S'
				|| data->map_game[y][x] == 'E' || data->map_game[y][x] == 'W'
				|| data->map_game[y][x] == 'C' || data->map_game[y][x] == 'F')
			{
				i = -1;
				while (data->map_game[y][x] != '\n')
					temp[++i] = data->map_game[y][x++];
				temp = get_img(data, temp, i);
			}
		}
	}
	free(temp);
}

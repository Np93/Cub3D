/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:47:56 by nhirzel           #+#    #+#             */
/*   Updated: 2022/08/19 00:24:47 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

char	*load_def_map(t_data *data, char *line)
{
	int	i;
	int	rep;

	i = 0;
	rep = 0;
	if (data->rep == 0)
		if (line[i] == '\0' || line[i] == '\n' || line == NULL)
			rep = 1;
	if (data->rep == 1 && (line == NULL || line[0] == '\n' || line[0] == '\0'))
		error_handle2(7);
	if (rep == 0)
	{
		(data->count)++;
		data->map[data->count] = ft_strdup(line);
		data->rep = 1;
	}
	i = strlen(line);
	while (i >= 0)
	{
		line[i] = '\0';
		i--;
	}
	return (line);
}

void	set_count_y(t_data *data)
{
	data->count_y = 0;
	while (data->map[data->count_y] != NULL)
		(data->count_y)++;
	(data->count_y)--;
}

void	get_map_game(t_data *data, int width, int h)
{
	int		x;
	char	*temp;
	int		i;

	data->count = -1;
	data->map = malloc(sizeof(char *) * ((h - (data->count_y)) + 1));
	temp = malloc(sizeof(char) * (width + 1));
	while (data->map_game[data->count_y] != NULL)
	{
		x = 0;
		i = -1;
		while (data->map_game[data->count_y][x] != '\0' )
		{
			temp[++i] = data->map_game[data->count_y][x];
			x++;
		}
		temp[i + 1] = '\0';
		temp = load_def_map(data, temp);
		(data->count_y)++;
	}
	data->map[(data->count) + 1] = NULL;
	set_count_y(data);
	free(temp);
}

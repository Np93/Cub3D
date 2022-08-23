/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrimap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:29:37 by nhirzel           #+#    #+#             */
/*   Updated: 2022/08/23 03:12:10 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

char	*ft_load_img(t_data *data, char *line, char *path, int nbr)
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
		path[++count] = line[i++];
	}
	path[count + 1] = '\0';
	if (path == NULL)
		error_handle(8);
	count_info_map(data, nbr);
	return (path);
}

void	check_badmap(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (data->count_y == -2)
	{
		while (line[i] != '\0')
		{
			if (line[i] == '1')
			{
				while (line[i] == '0' || line[i] == '1')
				{
					if (line[i + 1] == '\0' || line[i + 1] == '\n')
						error_handle3(6);
					i++;
				}
			}
			else if (line[i] != ' ')
				error_handle3(5);
			i++;
		}
	}
}

char	*get_img(t_data *data, char *line, int count)
{
	int	i;

	i = 0;
	line[count + 1] = '\0';
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		data->path_n = ft_load_img(data, line, data->path_n, 1);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		data->path_s = ft_load_img(data, line, data->path_s, 2);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		data->path_w = ft_load_img(data, line, data->path_w, 3);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		data->path_e = ft_load_img(data, line, data->path_e, 4);
	else if (line[i] == 'C')
		ft_coolor_c(data, line, 5);
	else if (line[i] == 'F')
		ft_coolor_f(data, line, 6);
	else
		check_badmap(data, line);
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
	if (data->token_n == 1 && data->token_s == 1
		&& data->token_w == 1 && data->token_e == 1
		&& data->up_int[0] == data->ref_up
		&& data->down_int[0] == data->ref_down)
	{
		if ((++(data->count)) == 1)
			data->count_y = y;
			data->rep = 0;
	}
}

void	get_wall(t_data *data, int width)
{
	int		x;
	int		y;
	char	*temp;
	int		i;

	y = -1;
	temp = malloc(sizeof(char) * (width + 1));
	while (data->map_game[++y] != NULL)
	{
		get_wall2(data, y);
		x = -1;
		while (data->map_game[y][++x] != '\0')
		{
			if (x == 0)
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

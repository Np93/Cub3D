/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:49:02 by nhirzel           #+#    #+#             */
/*   Updated: 2022/08/17 04:50:14 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	ft_coolor_f2(t_data *data, char *line)
{
	char	**spliter;
	int		i;
	int		count;

	spliter = ft_split(line, ',');
	i = 0;
	count = 0;
	while (spliter[count])
		count++;
	if (count > 3)
		error_handle2(2);
	else if (count < 3)
		error_handle3(4);
	data->ref_down = ft_atoi(spliter[0]);
	while (i < count)
	{
		data->down_int[i] = ft_atoi(spliter[i]);
		if (data->down_int[i] < 0 || data->down_int[i] > 255)
			error_handle2(0);
		i++;
	}
	while (i > 0)
		free(spliter[--i]);
	free(spliter);
}

void	ft_coolor_f(t_data *data, char *line)
{
	int		i;
	int		count;

	i = 0;
	count = -1;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && line[i - 1] != (line[i - 1] >= '0'
				&& line[i - 1] <= '9') && line[i - 1] != ','
			&& line[i + 1] != (line[i + 1] >= '0'
				&& line[i + 1] <= '9'))
			error_handle2(6);
		if (!(line[i] >= '0' && line[i] <= '9')
			&& line[i] != ',' && line[i] != ' ')
			error_handle2(4);
		if (line[i] != ' ')
			line[++count] = line[i];
		i++;
	}
	line[count + 1] = '\0';
	ft_coolor_f2(data, line);
}

void	ft_coolor_c2(t_data *data, char *line)
{
	char	**spliter;
	int		i;
	int		count;

	spliter = ft_split(line, ',');
	i = 0;
	count = 0;
	while (spliter[count])
		count++;
	if (count > 3)
		error_handle2(1);
	else if (count < 3)
		error_handle3(3);
	data->ref_up = ft_atoi(spliter[0]);
	while (i < count)
	{
		data->up_int[i] = ft_atoi(spliter[i]);
		if (data->up_int[i] < 0 || data->up_int[i] > 255)
			error_handle(9);
		i++;
	}
	while (i > 0)
		free(spliter[--i]);
	free(spliter);
}

void	ft_coolor_c(t_data *data, char *line)
{
	int		i;
	int		count;

	i = 0;
	count = -1;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && line[i - 1] != (line[i - 1] >= '0'
				&& line[i - 1] <= '9') && line[i - 1] != ','
			&& line[i + 1] != (line[i + 1] >= '0'
				&& line[i + 1] <= '9'))
			error_handle2(5);
		if (!(line[i] >= '0' && line[i] <= '9')
			&& line[i] != ',' && line[i] != ' ')
			error_handle2(3);
		if (line[i] != ' ')
			line[++count] = line[i];
		i++;
	}
	line[count + 1] = '\0';
	ft_coolor_c2(data, line);
}

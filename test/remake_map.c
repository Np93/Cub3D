/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remake_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:39:14 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 01:49:33 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	copyline(char *cpy, char *dst, int big)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < big - 1)
	{
		if (cpy[i] == '\n')
			break ;
		if (cpy[i] == ' ')
			dst[j] = '1';
		else
			dst[j] = cpy[i];
		i++;
		j++;
	}
	while (j < big - 1)
		dst[j++] = '1';
	dst[j++] = '\n';
	dst[j++] = '\0';
}

int	search_big(t_data *data)
{
	int	big;
	int	tmp;
	int	i;

	big = -1;
	i = -1;
	while (data->map[++i] != NULL)
	{
		tmp = ft_strlen(data->map[i]);
		if (big < tmp)
			big = tmp;
	}
	return (big);
}

void	change_space(char *dst)
{
	int	i;

	i = 0;
	while (dst[i] != '\0')
	{
		if (dst[i] == ' ')
			dst[i++] = '1';
		else
			i++;
	}
}

void	remake_map(t_data *data)
{
	int		big;
	int		i;
	char	*cpy;

	big = search_big(data);
	i = -1;
	while (data->map[++i] != NULL)
	{
		if (ft_strlen(data->map[i]) < (size_t)big)
		{
			cpy = ft_strdup(data->map[i]);
			free(data->map[i]);
			data->map[i] = malloc(sizeof(char) * big);
			copyline(cpy, data->map[i], big);
			free(cpy);
		}
		else
			change_space(data->map[i]);
	}
}

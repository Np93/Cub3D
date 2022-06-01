/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:13:02 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 21:25:48 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	verif_cf(char *map, int i)
{
	int	a;
	int	b;
	int	c;

	if (map[++i] != ' ')
		return (0);
	while (map[i] == ' ')
		i++;
	while (map[i] != '\n')
	{
		
	}
}

int	verifpath(char *path)
{
	int	fd;

	fd = open((const char *)path, O_RDONLY);
	if (fd == -1)
		return (0);
	return (1);
}

int	verif_nsew(char *map, int i)
{
	char	*path;
	int		j;

	if (map[i] == 'N' || map[i] == 'S')
		if (map[++i] != 'O')
			return (0);
	else if (map[i] == 'W')
		if (map[++i] != 'E')
			return (0);
	else if (map[i] == 'E')
		if (map[++i] != 'A')
			return (0);
	while (map[i] == ' ')
		i++;
	j = i;
	while (map[j] != '\n')
		j++;
	path = ft_strndup(map, i, j);
	if (!verifpath(path))
		return (0);
	return (j + 1);
}

int	verifmap(char *mapfile)
{
	int		fd;
	char	*map;
	int		i;

	fd = open((const char *)mapfile, O_RDONLY);
	if (fd == -1)
		return (4);
	map = get_next_line(fd);
	printf("%s\n", map);
	while (map[i] != '\0')
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W'
			|| map[i] == 'E')
			i = verifinfos(map, i);
		else if (map[i] == 'C' || map[i] == 'F')
			i = verif_CF(map. i);
		else
			i++;
		if (!i)
			return (2);
	}
//		if (!veriflab(map))
//			return (3);
	return (0);
}

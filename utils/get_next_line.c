/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:51:32 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/18 22:37:03 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

char	*readsave(int fd, char *save)
{
	char	*buff;
	int		ret;

	buff = (char *)malloc(sizeof(char) * 42 + 1);
	if (!buff)
		return (NULL);
	ret = 1;
	while (!(ft_strchr(save, '\n')) && ret != 0)
	{
		ret = read(fd, buff, 42);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*rest(char *save)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	while (save[a] != '\0' && save[a] != '\n')
		a++;
	if (save[a] == '\0')
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(save) - a + 1);
	if (!str)
		return (NULL);
	a++;
	while (save[a] != '\0')
		str[b++] = save[a++];
	str[b] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || 42 <= 0)
		return (NULL);
	save = readsave(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = rest(save);
	return (line);
}

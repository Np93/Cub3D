/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:51:32 by rmonney           #+#    #+#             */
/*   Updated: 2021/12/06 20:04:39 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*readsave(int fd, char *save)
{
	char	*buff;
	int		ret;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
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
	while (save[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
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
	while (save[a] != '\0')
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = readsave(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = rest(save);
	return (line);
}

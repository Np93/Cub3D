/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:53:45 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 17:10:21 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

size_t	ft_strlen(char *str)
{
	unsigned long	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char *save, char *buff)
{
	char			*str;
	int				a;
	int				b;

	a = -1;
	b = 0;
	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buff)) + 1);
	if (!str)
		return (NULL);
	if (save)
		while (save[++a] != '\0')
			str[a] = save[a];
	while (buff[b] != '\0')
		str[a++] = buff[b++];
	str[ft_strlen(save) + ft_strlen(buff)] = '\0';
	free(save);
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (0);
	while (s[a] != c && s[a] != '\0')
		a++;
	if (s[a] == '\0' && c != '\0')
		return (0);
	else
		return (1);
}

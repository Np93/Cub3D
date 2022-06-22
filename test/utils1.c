/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:08 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 21:32:31 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

char	*ft_strndup(char *str, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * end - start + 1);
	if (!ret)
		return (NULL);
	while (start < end)
		ret[i++] = str[start++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		n;

	n = 0;
	while (src[n] != '\0')
		n ++;
	dest = malloc(sizeof(*dest) * n + 1);
	if (!dest)
		return (NULL);
	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n ++;
	}
	dest[n] = '\0';
	return (dest);
}

int	exiter(void)
{
	exit(0);
	return (0);
}

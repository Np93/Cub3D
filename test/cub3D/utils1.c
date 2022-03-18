/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:08 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 20:48:30 by rmonney          ###   ########.fr       */
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

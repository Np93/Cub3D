/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:08 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 02:02:45 by rmonney          ###   ########.fr       */
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

int	exiter(t_data *data)
{
//	free(data->end.img);
//	free(data->w.img);
	mlx_destroy_image(data->mlx, data->end.img);
	mlx_destroy_image(data->mlx, data->w.img);
//	free(data->end.img);
//	free(data->w.img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
//	while (1)
//	{}
	exit(0);
	return (0);
}

void	print_info_str(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 340, 20, 0xFFFFFF, data->move_speed);
	mlx_string_put(data->mlx, data->win, 340, 40, 0xFFFFFF, data->pov_speed);
	mlx_string_put(data->mlx, data->win, 20, RESY - 20, 0xFFFFFF, data->ctrl);
	mlx_string_put(data->mlx, data->win, 20, RESY - 50, 0xFFFFFF, data->ctrl2);
	mlx_string_put(data->mlx, data->win, 20, RESY - 80, 0xFFFFFF, data->ctrl3);
	if (0 < data->cross)
		mlx_put_image_to_window(data->mlx, data->win, data->cross1, 935, 515);
	else
		mlx_string_put(data->mlx, data->win, 957, 544, 0x00FF00, "o");
}

int	empty_image(t_data *data)
{
	if (data->north.img == NULL)
		return (1);
	if (data->south.img == NULL)
		return (1);
	if (data->east.img == NULL)
		return (1);
	if (data->west.img == NULL)
		return (1);
	return (0);
}

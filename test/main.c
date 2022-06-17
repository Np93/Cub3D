/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:16:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/17 17:27:08 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 0;
	if (ac != 2)
	{
		error_handle(0);
		return (0);
	}
	while (av[1][i] != '\0')
		i++;
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u'
		|| av[1][i - 3] != 'c' || av[1][i - 4] != '.')
	{
		error_handle(1);
		return (0);
	}
	// Parsing de map //
	/*if (verifmap(av[1]))
	{
		error_handle(verifmap(av[1]));
		return (0);
	}*/

	// version provisoire pour booser sur le r-casting //
	data.map = get_map(av[1]);
	data.map_xsize = ft_strlen(data.map[0]) - 1;
	i = -1;
	while (data.map[++i] != NULL)
		printf("%s", data.map[i]);
	data.map_ysize = i;
	data.pos_x = 4;
	data.pos_y = 3;
//	printf("map x = %d & map y = %d\n", data.map_xsize, data.map_ysize);
	/////////////////////////////////////////////////////

	start(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:16:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 21:35:20 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 0;
	if (ac != 2)
		error_handle(0);
	while (av[1][i] != '\0')
		i++;
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u'
		|| av[1][i - 3] != 'c' || av[1][i - 4] != '.')
		error_handle(1);
/*	Parsing de map
	version provisoire pour bosser sur le r-casting*/
	data.map = get_map(av[1]);
	get_map_infos(&data);
	start(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:16:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 19:00:04 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	int	i;

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
	if (verifmap(av[1]))
	{
		error_handle(verifmap(av[1]));
		return (0);
	}
//	start(av[1]);
	return (0);
}

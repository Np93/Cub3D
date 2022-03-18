/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:18:41 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 20:03:45 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_handle(int error)
{
	if (error == 0)
		printf("Wrong number of arguments\n");
	else if (error == 1)
		printf("Your map should be .cub\n");
	else if (error == 2)
		printf("Error in the infos of map\n");
	else if (error == 3)
		printf("Error in the map structure\n");
	else if (error == 4)
		printf("Your map doesn't exists\n");
	exit(0);
}

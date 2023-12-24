/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:18:41 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 20:25:28 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_handle(int error)
{
	if (error == 0)
		printf("Wrong number of arguments\n");
	if (error == 1)
		printf("Your map should be .cub\n");
	if (error == 2)
		printf("Error in the infos of map\n");
	if (error == 3)
		printf("Error in the map structure\n");
	if (error == 4)
		printf("Your map doesn't exists\n");
	if (error == 5)
		printf("Error : fatal malloc\n");
	if (error == 6)
		printf("Error: could'nt get image\n");
	exit(0);
}

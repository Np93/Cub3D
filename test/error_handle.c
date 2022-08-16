/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:18:41 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/17 01:46:19 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_handle(int error)
{
	if (error == 0)
		printf("Error\n Wrong number of arguments\n");
	if (error == 1)
		printf("Error\n Your map should be .cub\n");
	if (error == 2)
		printf("Error\n in the infos of map\n");
	if (error == 3)
		printf("Error\n in the map structure\n");
	if (error == 4)
		printf("Error\n Your map doesn't exists\n");
	if (error == 5)
		printf("Error\n fatal malloc\n");
	if (error == 6)
		printf("Error\n could'nt get image\n");
	if (error == 7)
		printf("Error\n your img should be .xpm\n");
	if (error == 8)
		printf("Error\n path for img is empty\n");
	if (error == 9)
		printf("Error\n value in C too high or low\n" );
	exit(0);
}

void	error_handle2(int error)
{
	if (error == 0)
		printf("Error\n value in F too high or low\n");
	if (error == 1)
		printf("Error\n too many arguments in C\n");
	if (error == 2)
		printf("Error\n too many arguments in F\n");
	if (error == 3)
		printf("Error\n character not accepted in C\n");
	if (error == 4)
		printf("Error\n character not accepted in F\n");
	if (error == 5)
		printf("Error\n extra space in C\n");
	if (error == 6)
		printf("Error\n extra space in F\n");
	if (error == 7)
		printf("Error\n invalid map, empty line in map\n");
	if (error == 8)
		printf("Error\n invalid map, empty line in map\n");
	if (error == 9)
		printf("Error\n no player on the map\n" );
	exit(0);
}

void	error_handle3(int error)
{
	if (error == 0)
		printf("Error\n invalid character in map\n");
	if (error == 1)
		printf("Error\n player outside the map\n");
	if (error == 2)
		printf("Error\n player outside the map\n");
	exit(0);
}

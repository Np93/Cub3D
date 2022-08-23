/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:18:41 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/23 03:57:07 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

void	error_handle(int error)
{
	if (error == 0)
		printf("Error\nWrong number of arguments\n");
	if (error == 1)
		printf("Error\nYour map should be .cub\n");
	if (error == 2)
		printf("Error\nin the infos of map\n");
	if (error == 3)
		printf("Error\nin the map structure\n");
	if (error == 4)
		printf("Error\nYour map doesn't exists\n");
	if (error == 5)
		printf("Error\nfatal malloc\n");
	if (error == 6)
		printf("Error\ncould'nt get image\n");
	if (error == 7)
		printf("Error\nyour img should be .xpm\n");
	if (error == 8)
		printf("Error\npath for img is empty\n");
	if (error == 9)
		printf("Error\nvalue in C too high '255' or low '0'\n" );
	exit(0);
}

void	error_handle2(int error)
{
	if (error == 0)
		printf("Error\nvalue in F too high '255' or low '0'\n");
	if (error == 1)
		printf("Error\ntoo many arguments in C\n");
	if (error == 2)
		printf("Error\ntoo many arguments in F\n");
	if (error == 3)
		printf("Error\ncharacter not accepted in C\n");
	if (error == 4)
		printf("Error\ncharacter not accepted in F\n");
	if (error == 5)
		printf("Error\nextra space in C\n");
	if (error == 6)
		printf("Error\nextra space in F\n");
	if (error == 7)
		printf("Error\ninvalid map, empty line in map\n");
	if (error == 8)
		printf("Error\ntoo many players on the map\n");
	if (error == 9)
		printf("Error\nno player on the map\n" );
	exit(0);
}

void	error_handle3(int error)
{
	if (error == 0)
		printf("Error\ninvalid character in map\n");
	if (error == 1)
		printf("Error\nplayer outside the map\n");
	if (error == 2)
		printf("Error\nmap not closed\n");
	if (error == 3)
		printf("Error\nargument are missing in C\n");
	if (error == 4)
		printf("Error\nargument are missing in F\n");
	if (error == 5)
		printf("Error\ncharacter not allowed in map infos\n");
	if (error == 6)
		printf("Error\ndescription of the maze before the infos\n");
	if (error == 7)
		printf("Error\ndouble in map informations\n");
	if (error == 8)
		printf("Error\nmissing map info\n");
	exit(0);
}

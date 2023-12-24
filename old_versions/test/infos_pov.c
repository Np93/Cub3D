/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_pov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:43:41 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/14 00:31:23 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	infos_pov(t_data *data, t_rc *rc, float angle)
{
	printf("im on case x:[%d] y:[%d], my pov hit case x:[%d] y:[%d] and ",
		(int)data->pos_x, (int)data->pos_y,
		rc->mapx, rc->mapy);
	if (angle <= PI)
		printf("Im looking en haut ");
	else
		printf("Im looking en bas ");
	if ((PI / 2) > angle || angle > ((3 * PI) / 2))
		printf("a droite ");
	else
		printf("a gauche ");
	printf("with un angle de %f\n", angle);
}

void	what_hit(t_rc *rc)
{
	if (rc->what_wall == 'n')
		printf("ray[%d] hit wall NORTH ", rc->num);
	if (rc->what_wall == 's')
		printf("ray[%d] hit wall SOUTH ", rc->num);
	if (rc->what_wall == 'e')
		printf("ray[%d] hit wall EAST ", rc->num);
	if (rc->what_wall == 'w')
		printf("ray[%d] hit wall WEST ", rc->num);
	printf("at dist = [%f], wallx = [%f] & texx = [%d]\n",
		rc->dist, rc->wallx, rc->texx);
	rc->num++;
	if (rc->num == 100)
		printf("\n\n");
}

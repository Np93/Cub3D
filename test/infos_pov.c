/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_pov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:43:41 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 20:02:46 by rmonney          ###   ########.fr       */
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

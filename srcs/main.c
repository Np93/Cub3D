/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:16:23 by rmonney           #+#    #+#             */
/*   Updated: 2022/08/18 23:43:50 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	int		height;
	int		width;
	t_data	data;

	if (ac != 2)
		error_handle(0);
	check_ber(&data, av[1]);
	height = count_lign(av[1]);
	data.map_game = get_map(av[1], height);
	width = count_col(&data);
	get_wall(&data, width);
	get_map_game(&data, width, height);
	get_map_infos(&data);
	if (data.player == 0)
		error_handle2(9);
	if (data.player != 1)
		error_handle2(8);
	start(&data);
	return (0);
}

void	init_info_str(t_data *data)
{
	data->move_speed = ft_strdup("PLAYER SPEED = [1]");
	data->pov_speed = ft_strdup("POV SPEED = [1]");
	data->ctrl = ft_strdup("MOVES : [A] [S] [D] [W] [LEFT] [RIGHT]");
	data->ctrl2 = ft_strdup("SPEED CTRL : [-] [+]  POV CTRL : [DOWN] [UP]");
	data->ctrl3 = ft_strdup("CHANGE CROSSAIR : [C]");
}

void	start(t_data *data)
{
	remake_map(data);
	init_info_str(data);
	mlx_initer(data);
	if (empty_image(data))
	{
		printf("ERROR \nWrong texture path\n");
		exit(0);
	}
	set_ray(data);
	raycast(data);
	print_minimap(data);
	print_info_str(data);
	mlx_put_image_to_window(data->mlx, data->win, data->fps1, 780, 720);
	mlx_hook(data->win, 2, 1L << 1, deal_key, data);
	mlx_hook(data->win, 17, 0, exiter, data);
	mlx_loop(data->mlx);
	return ;
}

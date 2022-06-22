/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:20:40 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/22 20:11:03 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stddef.h>
# include <math.h>
# include "./minilibx/mlx.h"

# define BUFFER_SIZE 42

	// KEY HOOK CODES //

	//ESC = 53 // X = 7 //

		// W = 13 //
// A = 0 // S = 1 // D = 2 //

//   <- = 123 // 124 = ->  //

typedef struct s_data {
	char	**map;
	int		map_xsize;
	int		map_ysize;
	float	pos_x;
	float	pos_y;
	float	look;
	void	*mlx;
	void	*win_m;
	void	*win_g;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	void	*up;
	void	*down;
	void	*w_mmap;
	void	*f_mmap;
	void	*red_pix;
	char	*addr_r;
	int		bpp_r;
	int		line_length_r;
	int		endian_r;
	void	*green_pix;
	char	*addr_g;
	int		bpp_g;
	int		line_length_g;
	int		endian_g;
}	t_data;

typedef struct s_rc {
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	float	a;
	float	b;
	float	distx;
	float	disty;
	float	deltax;
	float	deltay;
	float	lenx;
	float	leny;
	float	collx;
	float	colly;
	int		hit;
}	t_rc;

# define MOVE 0.15
# define POV 0.1
# define PMAP 40
# define PI 3.141593

void	error_handle(int error);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *save, char *buff);
size_t	ft_strlen(char *str);
int		verifmap(char *mapfile);
int		verif_snew(char *map, int i);
int		verif_cf(char *map, int i);
int		verifpath(char *path);
char	*ft_strndup(char *str, int start, int end);
char	*ft_strdup(char *src);
int		ft_atoi(char *str);
char	**get_map(char *map_path);
void	get_map_infos(t_data *data);
void	get_angle_pov(t_data *data, char dir);
void	start(t_data *data);
void	mlx_initer(t_data *data);
void	red_pix_maker(t_data *data);
void	green_pix_maker(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_minimap(t_data *data);
int		exiter(void);
int		deal_key(int key, t_data *data);
int		colliwall(int key, t_data *data);
void	key_pov(t_data *data, int key);
void	print_pov_angle(t_data *data);
void	collipov(t_data *data, t_rc *rc, float angle);
void	collipov2(t_data *data, t_rc *rc, float angle);
float	angle_correction(float angle);
void	infos_pov(t_data *data, t_rc *rc, float angle);

#endif

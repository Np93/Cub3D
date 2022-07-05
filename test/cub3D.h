/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:20:40 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/05 20:54:21 by rmonney          ###   ########.fr       */
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
# include "../minilibx/mlx.h"

	// KEY HOOK CODES //

// ESC = 53 // X = 7 // N = 45 // K = 40 // R = 15 //

		// W = 13 //
// A = 0 // S = 1 // D = 2 //

			// UP = 126 //
// L = 123 // D = 125 // R = 124 //

// - = 78 // + = 69 // ON NUMPAD

typedef struct s_tex {
	void	*img;
	int		x;
	int		y;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_tex;

typedef struct s_data {
	int		which_key;
	char	**map; // N
	int		map_xsize; //N taille en x
	int		map_ysize; //N taille en y
	float	pos_x; //N pose du perso
	float	pos_y; //N pose du perso
	float	look; //N -> direction nsew
	int		x_ok;
	int		y_ok;
	void	*mlx;
	void	*win;
	char	*path_n;
	char	*path_s;
	char	*path_e;
	char	*path_w;
	t_tex	north; //N
	t_tex	south; //N
	t_tex	east; //N
	t_tex	west; //N
	void	*up; //N
	void	*down; //N
	void	*w_mmap;
	void	*f_mmap;
	void	*red_pix;
	void	*green_pix;
	void	*map_frame;
	float	move;
	float	pov;
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
	int		hit;
	int		x;
}	t_rc;

typedef struct s_minimap {
	int		x;
	int		y;
	int		x_win;
	int		y_win;
	float	diff_x;
	float	diff_y;
}	t_minimap;

typedef struct s_ray {
	t_tex	src;
	t_tex	dst;
	int		srcx;
	int		srcy;
	int		dstx;
	int		dsty;
	float	ratio;
	float	i;
}	t_ray;

# define PMAP 30
# define PI 3.141593
# define PTEX 64
# define RESX 1920
# define RESY 1080

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
void	print_minimap(t_data *data);
void	print_wall(t_data *data);
void	print_wall2(t_data *data, t_minimap *map);
void	print_floor(t_data *data);
void	print_floor2(t_data *data, t_minimap *map);
int		exiter(void);
int		deal_key(int key, t_data *data);
void	settings_keys(int key, t_data *data);
void	colliwall(int key, t_data *data);
void	key_pov(t_data *data, int key);
void	print_pov_angle(t_data *data);
void	collipov(t_data *data, t_rc *rc, float angle);
void	collipov2(t_data *data, t_rc *rc, float angle);
float	angle_correction(float angle);
void	infos_pov(t_data *data, t_rc *rc, float angle);
int		max_len(t_rc *rc, t_data *data, float angle);
int		limit(t_minimap *map);
void	raycast(t_data *data);
void	cpy_pixel(t_ray *ray);

#endif

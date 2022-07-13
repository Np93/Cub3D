/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:20:40 by rmonney           #+#    #+#             */
/*   Updated: 2022/07/13 23:27:40 by rmonney          ###   ########.fr       */
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
// SPACE = 49 //

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
	char	init_dir;
	int		which_key;
	char	**map;
	char	**map_game;
	int		map_xsize;
	int		map_ysize;
	float	pos_x;
	float	pos_y;
	float	look;
	int		x_ok;
	int		y_ok;
	void	*mlx;
	void	*win;
	char	*path_n;
	char	*path_s;
	char	*path_e;
	char	*path_w;
	t_tex	north;
	t_tex	south;
	t_tex	east;
	t_tex	west;
	void	*fps1;
	void	*fps2;
	int		up_int[3];
	int		down_int[3];
	int		count;
	char	up_char[3];
	char	down_char[3];
	void	*w_mmap;
	void	*f_mmap;
	void	*red_pix;
	void	*green_pix;
	void	*map_frame;
	float	move;
	float	pov;
	float	dirx;
	float	olddirx;
	float	diry;
	float	planex;
	float	oldplanex;
	float	planey;
	t_tex	end;
	t_tex	white;
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
	float	dist;
	float	fe_diff;
	float	wallx;
	int		texx;
	int		hit;
	int		x;
	int		mod;
	int		num;
	char	what_wall;
	int		srcx;
	int		srcy;
	int		dstx;
	int		dsty;
	int		h;
	int		starth;
	int		endh;
	float	dist_saved;
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
	int		x;
	float	posx;
	float	posy;
	int		mapx;
	int		mapy;
	float	planex;
	float	planey;
	int		num;
	float	camerax;
	float	raydirx;
	float	raydiry;
	float	sidedistx;
	float	sidedisty;
	float	deltax;
	float	deltay;
	float	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	char	what_wall;
	float	wallx;
	int		texx;
	int		h;
	int		starth;
	int		endh;
	int		srcx;
	int		srcy;
	int		dstx;
	int		dsty;
}	t_ray;

# define PMAP 30
# define PI 3.141593
# define PTEX 64
# define RESX 1920
# define RESY 1080
# define HEIGHT 900
# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

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
void	print_background(t_data *data);
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
void	collipov(t_data *data, t_rc *rc, float angle, int mod);
void	collipov2(t_data *data, t_rc *rc, float angle);
void	collipov3(t_data *data, t_rc *rc, float angle);
void	collipov4(t_data *data, t_rc *rc, float angle);
float	angle_correction(float angle);
void	infos_pov(t_data *data, t_rc *rc, float angle);
int		max_len(t_rc *rc, t_data *data, float angle);
int		limit(t_minimap *map);
void	raycast_test(t_data *data);
void	cpy_pixel(t_tex *dst, t_tex *src, t_rc *rc);
void	cpy_color(t_tex *dst, char color[3], t_rc *rc);
void	raycast(t_data *data);
void	make_final(t_data *data, t_rc *rc);
void	get_wall(t_data *data);
char	**ft_split(char *s, char c);
void	get_map_game(t_data *data);
void	shoot(t_data *data);

#endif

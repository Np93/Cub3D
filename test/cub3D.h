/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:20:40 by rmonney           #+#    #+#             */
/*   Updated: 2022/06/28 02:30:49 by rmonney          ###   ########.fr       */
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
	char	**map;   // N
	int		map_xsize; //N taille en x
	int		map_ysize; //N taille en y
	float	pos_x; //N pose du perso
	float	pos_y; //N pose du perso
	float	look; //N -> direction nsew
	float	first_x;
	float	first_y;
	void	*mlx;
	void	*win_m;
	void	*win_g;
	void	*north; //N
	void	*south; //N
	void	*east; //N
	void	*west; //N
	void	*up;  //N
	void	*down; //N
	void	*w_mmap;
	void	*f_mmap;
	void	*red_pix;
	void	*red_big;
	void	*red_max;
	void	*green_pix;
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

# define MOVE 0.15
# define POV 0.15
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
void	print_minimap(t_data *data);
void	print_wall(t_data *data);
void	print_floor(t_data *data);
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

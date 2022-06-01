/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:20:40 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/01 21:24:29 by rmonney          ###   ########.fr       */
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
int		ft_atoi(char *str);

#endif

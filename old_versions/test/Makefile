# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 15:17:33 by rmonney           #+#    #+#              #
#    Updated: 2022/08/17 04:50:41 by nhirzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= get_next_line.c\
			  get_next_line_utils.c\
			  error_handle.c\
			  main.c\
			  verifmap.c\
			  utils1.c\
			  get_map.c\
			  init.c\
			  minimap.c\
			  minimap2.c\
			  minimap3.c\
			  deal_keys.c\
			  deal_keys2.c\
			  deal_keys3.c\
			  infos_pov.c\
			  raycast.c\
			  raycast2.c\
			  vrimap.c\
			  ft_split.c\
			  ft_atoi.c\
			  get_map_game.c\
			  remake_map.c\
			  ft_coolor.c\

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= cub3D

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ../minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

.c.o:		
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${MLXPATH}
			${CC} ${FLAGS} ${INCLUDEMLX} -o ${NAME} ${OBJS} ${LMLX} ${FRAMEWORK}

all:		${NAME}

good:		${NAME} clean

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

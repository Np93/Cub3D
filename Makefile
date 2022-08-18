# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 15:17:33 by rmonney           #+#    #+#              #
#    Updated: 2022/08/18 22:46:39 by rmonney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= utils/get_next_line.c\
			  utils/get_next_line_utils.c\
			  srcs/error_handle.c\
			  srcs/main.c\
			  srcs/verifmap.c\
			  utils/utils1.c\
			  srcs/get_map.c\
			  srcs/init.c\
			  srcs/minimap.c\
			  srcs/minimap2.c\
			  srcs/minimap3.c\
			  srcs/deal_keys.c\
			  srcs/deal_keys2.c\
			  srcs/deal_keys3.c\
			  utils/infos_pov.c\
			  srcs/raycast.c\
			  srcs/raycast2.c\
			  srcs/vrimap.c\
			  utils/ft_split.c\
			  utils/ft_atoi.c\
			  srcs/get_map_game.c\
			  srcs/remake_map.c\
			  srcs/ft_coolor.c\
			  srcs/setting.c\

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= cub3D

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx

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

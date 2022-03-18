# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 15:17:33 by rmonney           #+#    #+#              #
#    Updated: 2022/03/01 21:12:36 by rmonney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= get_next_line.c get_next_line_utils.c error_handle.c main.c verifmap.c utils1.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= cub3D

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

.c.o:		
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${MLXPATH}
			${CC} ${FLAGS} ${INCLUDEMLX} -o ${NAME} ${OBJS} ${LMLX} ${FRAMEWORK}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

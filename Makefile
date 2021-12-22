# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstrong <bstrong@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 17:42:40 by bstrong           #+#    #+#              #
#    Updated: 2021/12/22 21:00:28 by bstrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
FLAGS = -o3 -Werror -Wall -Wextra -g

SRC_PATH = ./src/

SRC_LST =	main.c			get_next_line.c		get_next_line_utils.c\
			ft_destroy.c	ft_split.c			ft_struct.c\
			ft_atoi.c		ft_reader.c			ft_draw.c\
			ft_controls.c	ft_rotate.c			ft_colors.c\
			ft_mouse.c

SRC = $(addprefix $(SRC_PATH), $(SRC_LST))

HEADERS = ./inc/get_next_line.h ./inc/fdf.h

OBJ = $(patsubst %.c,%.o,$(SRC))

LIBS =  -Lmlx -lmlx 

.PHONY : all clean fclean re

all : $(LIBS) $(NAME)

$(LIBS):
	$ make -C ./mlx all

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS) -framework OpenGL -framework AppKit

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -I./inc/ -Imlx  -c $< -o $@

clean:
	make -C ./mlx clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
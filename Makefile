# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 21:23:20 by mtellami          #+#    #+#              #
#    Updated: 2023/02/13 16:02:23 by mtellami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror  $(INC)
INC = -I inc
MLX =  -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/ft_strlen.c libft/ft_dprintf.c libft/ft_errors.c libft/ft_strcmp.c\

SRC = src/cub3d.c src/map_render.c\

OBJ = $(SRC:.c=.o) $(LIBFT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all
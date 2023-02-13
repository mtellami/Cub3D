# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 21:23:20 by mtellami          #+#    #+#              #
#    Updated: 2023/02/13 18:30:28 by mtellami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror $(INC) #-fsanitize=address -g3
INC = -I inc
MLX =  -lmlx -framework OpenGL -framework AppKit

NONE = '\033[0m'
GREEN = '\033[0;32m'
GRAY = '\033[2;37m'
ITALIC = '\033[3m '

LIBFT = libft/ft_strlen.c libft/ft_dprintf.c libft/ft_errors.c libft/ft_strcmp.c\
	libft/ft_free.c libft/ft_concate.c libft/ft_strjoin.c libft/ft_strdup.c\
	libft/ft_strchr.c\

SRC = src/cub3d.c src/map_render.c src/read_map.c gnl/get_next_line.c\
	gnl/gnl_utils.c\

OBJ = $(SRC:.c=.o) $(LIBFT:.c=.o)

.c.o :
	@echo $(GRAY) "     - Making $<..." $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo $(ITALIC)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

clean :
	@echo $(ITALIC)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -fr $(OBJ)

fclean : clean
	@echo $(ITALIC)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -fr $(NAME)

re : fclean all
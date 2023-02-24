/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:43:37 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/24 16:43:39 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef define
# define CUB3D

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>

# define WIDTH 1024
# define HEIGHT 512
# define SIZE 32
# define PI 3.141592653

enum e_key
{
	ESC_KEY = 53,
	W_KEY = 13,
	S_KEY = 1,
	A_KEY = 0,
	D_KEY = 2,
	RIGHT_KEY = 124,
	LEFT_KEY = 123,
};

typedef struct s_player
{
	int		px;
	int		py;
	float	pa;
}	t_player;

typedef struct s_map
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int*	floor;
	int*	ceil;
	char	**map;
}	t_map;

typedef struct s_main
{
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*window;
}	t_main;

/* ---------- Libft ---------- */


/* ---------- Src ---------- */


#endif
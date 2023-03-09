/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:23:24 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:48:48 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include <limits.h>
# include <float.h>

# define TILE_SIZE 32
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

# define NUM_RAYS 1280
# define MOVE_SPEED 5.0
# define ROTATE_SPEED 5.0

# define TEXTURE_DIMENTION 32

enum e_hit
{
	HORIZONTAL_HIT,
	VERTICAL_HIT,
};

enum e_direction
{
	FACING_UP,
	FACING_DOWN,
	FACING_RIGHT,
	FACING_LEFT,
};

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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	double	angle;
	double	x_wall_hit;
	double	y_wall_hit;
	double	distance;
	int		hit_side;
	int		wall_height;
}	t_ray;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_player
{
	double		angle;
	t_vector	vector;
	t_ray		*rays;
	double		fov;
}	t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_map
{
	t_img	_north;
	t_img	_south;
	t_img	_west;
	t_img	_east;
	t_rgb	_floor;
	t_rgb	_ceil;
	char	**map;
}	t_map;

typedef struct s_main
{
	t_map		map;
	t_player	player;
	t_img		img;
	void		*mlx;
	void		*window;
}	t_main;

/* ---------- Src ---------- */
void		initialize(t_main *main, t_parser *parse);
void		raycasting(t_main *main);
int			key_event(int key, void	*param);
int			_cross(void *param);
void		_move(t_main *main, double angle, int sign);
void		_rotate(t_main *main, int sign);
double		_distance(t_vector start, t_vector end);
double		_angle(double angle);
int			map_has_wall_at(char **map, double x, double y);
void		display(t_main *main);
t_vector	horizontal_raycast(t_main *main, double rayAngle);
t_vector	vertical_raycast(t_main *main, double rayAngle);
void		render(t_main *main);
int			wall_top_pixel(t_main *main, int i);
int			wall_bottom_pixel(t_main *main, int i);
int			_rgb_color(t_rgb rgb);
int			_pixel_color(t_img *img, int x, int y);
int			_direction(double angle, enum e_direction look);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 01:37:10 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:38:43 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_initialize(t_main *main, t_parser *parse)
{
	int		size;

	size = TEXTURE_DIMENTION;
	main->map._north.img = mlx_xpm_file_to_image
		(main->mlx, parse->texture[0], &size, &size);
	main->map._north.addr = mlx_get_data_addr(main->map._north.img,
			&main->map._north.bits_per_pixel, &main->map._north.line_length,
			&main->map._north.endian);
	main->map._south.img = mlx_xpm_file_to_image
		(main->mlx, parse->texture[1], &size, &size);
	main->map._south.addr = mlx_get_data_addr(main->map._south.img,
			&main->map._south.bits_per_pixel, &main->map._south.line_length,
			&main->map._south.endian);
	main->map._west.img = mlx_xpm_file_to_image
		(main->mlx, parse->texture[2], &size, &size);
	main->map._west.addr = mlx_get_data_addr(main->map._west.img,
			&main->map._west.bits_per_pixel, &main->map._west.line_length,
			&main->map._west.endian);
	main->map._east.img = mlx_xpm_file_to_image
		(main->mlx, parse->texture[3], &size, &size);
	main->map._east.addr = mlx_get_data_addr(main->map._east.img,
			&main->map._east.bits_per_pixel, &main->map._east.line_length,
			&main->map._east.endian);
}

void	map_initialize(t_main *main, t_parser *parse)
{
	textures_initialize(main, parse);
	main->map._floor.r = parse->c_floor[0];
	main->map._floor.g = parse->c_floor[1];
	main->map._floor.b = parse->c_floor[2];
	main->map._ceil.r = parse->c_ceiling[0];
	main->map._ceil.g = parse->c_ceiling[1];
	main->map._ceil.b = parse->c_ceiling[2];
	main->map.map = parse->map;
}

void	initialize(t_main *main, t_parser *parse)
{
	main->mlx = mlx_init();
	if (!main->mlx)
		ft_errors("fail initialize mlx");
	main->window = mlx_new_window(main->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	if (!main->window)
		ft_errors("fail opening window");
	map_initialize(main, parse);
	main->player.vector.x = parse->p_indices[0] * TILE_SIZE;
	main->player.vector.y = parse->p_indices[1] * TILE_SIZE;
	main->player.fov = 60 * (M_PI / 180);
	main->player.rays = NULL;
	if (parse->position == NORTH)
		main->player.angle = 1.5 * M_PI;
	else if (parse->position == SOUTH)
		main->player.angle = 0.5 * M_PI;
	else if (parse->position == WEST)
		main->player.angle = M_PI;
	else if (parse->position == EAST)
		main->player.angle = 0;
}

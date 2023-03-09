/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:37:59 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:32:50 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_top_pixel(t_main *main, int i)
{
	double	perp_distance;
	double	distance_proj_plane;
	int		wall_strip_height;
	int		wall_top_pixel;

	perp_distance = main->player.rays[i].distance
		* cos(main->player.rays[i].angle - main->player.angle);
	distance_proj_plane = (WINDOW_WIDTH / 2)
		/ tan(main->player.fov / 2);
	wall_strip_height = (int)((TILE_SIZE / perp_distance)
			* distance_proj_plane);
	if (wall_strip_height < 0 || wall_strip_height > WINDOW_HEIGHT)
		wall_strip_height = WINDOW_HEIGHT;
	main->player.rays[i].wall_height = wall_strip_height;
	wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
	return (wall_top_pixel);
}

int	wall_bottom_pixel(t_main *main, int i)
{
	int		wall_bottom_pixel;

	wall_bottom_pixel = (WINDOW_HEIGHT / 2)
		+ (main->player.rays[i].wall_height / 2);
	if (wall_bottom_pixel > WINDOW_HEIGHT)
		wall_bottom_pixel = WINDOW_HEIGHT;
	return (wall_bottom_pixel);
}

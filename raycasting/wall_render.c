/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:54:01 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:13:24 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_offset(t_main *main, int i, int top, char v)
{
	int	offset;

	if (v == 'X')
	{
		if (main->player.rays[i].hit_side == HORIZONTAL_HIT)
			offset = (int)main->player.rays[i].x_wall_hit % TILE_SIZE;
		else
			offset = (int)main->player.rays[i].y_wall_hit % TILE_SIZE;
	}
	else
	{
		offset = (top + (main->player.rays[i].wall_height / 2)
				- (WINDOW_HEIGHT / 2)) * ((double)TEXTURE_DIMENTION
				/ main->player.rays[i].wall_height);
	}
	return (offset);
}

void	horizontal_render(t_main *main, int i, int top, t_vector offset)
{
	if (_direction(main->player.rays[i].angle, FACING_UP))
		ft_mlx_pixel_put(&main->img, i, top,
			_pixel_color(&main->map._north, offset.x, offset.y));
	else
		ft_mlx_pixel_put(&main->img, i, top,
			_pixel_color(&main->map._south, offset.x, offset.y));
}

void	vertical_render(t_main *main, int i, int top, t_vector offset)
{
	if (_direction(main->player.rays[i].angle, FACING_RIGHT))
		ft_mlx_pixel_put(&main->img, i, y,
			_pixel_color(&main->map._west, offset.x, offset.y));
	else
		ft_mlx_pixel_put(&main->img, i, y,
			_pixel_color(&main->map._east, offset.x, offset.y));
}

void	render_wall(t_main *main, int top, int bottom, int i)
{
	t_vector	offset;

	offset.x = _offset(main, i, top, 'X');
	while (top < bottom)
	{
		offset.y = _offset(main, i, top, 'Y');
		if (main->player.rays[i].hit_side == HORIZONTAL_HIT)
			horizontal_render(main, i, top, offset);
		else
			vertical_render(main, i, top, offset);
		top++;
	}
}

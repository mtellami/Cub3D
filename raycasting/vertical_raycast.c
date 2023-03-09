/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_raycast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:52:20 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 21:42:38 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_vertical_intercept(t_main *main, double rayAngle)
{
	t_vector	intercept;

	intercept.x = floor(main->player.vector.x / TILE_SIZE) * TILE_SIZE;
	if (_direction(rayAngle, FACING_RIGHT))
		intercept.x += TILE_SIZE;
	intercept.y = main->player.vector.y + (intercept.x - main->player.vector.x)
		* tan(rayAngle);
	return (intercept);
}

t_vector	get_vertical_steps(double rayAngle)
{
	t_vector	step;

	step.x = TILE_SIZE;
	if (_direction(rayAngle, FACING_LEFT))
		step.x *= -1;
	step.y = TILE_SIZE * tan(rayAngle);
	if (_direction(rayAngle, FACING_UP) && step.y > 0)
		step.y *= -1;
	if (_direction(rayAngle, FACING_DOWN) && step.y < 0)
		step.y *= -1;
	return (step);
}

void	set_vert_check(t_vector *to_check, t_vector next_touch, double rayAngle)
{
	to_check->x = next_touch.x;
	if (_direction(rayAngle, FACING_LEFT))
		to_check->x--;
	to_check->y = next_touch.y;
}

t_vector	vertical_raycast(t_main *main, double rayAngle)
{
	t_vector	step;
	t_vector	intercept;
	t_vector	next_touch;
	t_vector	to_check;

	next_touch.x = -1;
	next_touch.y = -1;
	intercept = get_vertical_intercept(main, rayAngle);
	step = get_vertical_steps(rayAngle);
	next_touch.x = intercept.x;
	next_touch.y = intercept.y;
	while (next_touch.x >= 0 && next_touch.x <= WINDOW_WIDTH
		&& next_touch.y >= 0 && next_touch.y <= WINDOW_HEIGHT)
	{
		set_vert_check(&to_check, next_touch, rayAngle);
		if (map_has_wall_at(main->map.map, to_check.x, to_check.y))
			return (next_touch);
		else
		{
			next_touch.x += step.x;
			next_touch.y += step.y;
		}
	}
	return (next_touch);
}

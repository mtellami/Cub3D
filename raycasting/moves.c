/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:49:07 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:31:13 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_rotate(t_main *main, int sign)
{
	main->player.angle = _angle(main->player.angle
			+ (ROTATE_SPEED / 360 * M_PI * 2 * sign));
}

void	_move(t_main *main, double angle, int sign)
{
	double	new_x;
	double	new_y;

	new_x = main->player.vector.x + (cos(angle) * MOVE_SPEED * sign);
	new_y = main->player.vector.y + (sin(angle) * MOVE_SPEED * sign);
	if (!map_has_wall_at(main->map.map, new_x, new_y))
	{
		main->player.vector.x = new_x;
		main->player.vector.y = new_y;
	}
}

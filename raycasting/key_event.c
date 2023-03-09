/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:34:55 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:42:42 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_cross(void *param)
{
	(void)param;
	exit(0);
	return (1);
}

int	key_event(int key, void	*param)
{
	t_main	*main;

	main = (t_main *)param;
	if (key == 53)
		exit(1);
	else if (key == W_KEY)
		_move(main, main->player.angle, 1);
	else if (key == S_KEY)
		_move(main, main->player.angle, -1);
	else if (key == A_KEY)
		_move(main, main->player.angle + 0.5 * M_PI, -1);
	else if (key == D_KEY)
		_move(main, main->player.angle + 0.5 * M_PI, 1);
	else if (key == RIGHT_KEY)
		_rotate(main, 1);
	else if (key == LEFT_KEY)
		_rotate(main, -1);
	mlx_clear_window(main->mlx, main->window);
	display(main);
	return (0);
}

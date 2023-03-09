/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:26:48 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 22:33:40 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_main *main)
{
	raycasting(main);
	render(main);
}

int	main(int argc, char **argv)
{
	t_main		main;
	t_parser	*parse;

	if (argc != 2)
		ft_errors("Usage: ./cub3d map.cub");
	parse = parser(argv[1]);
	initialize(&main, parse);
	mlx_hook(main.window, 2, 0, &key_event, &main);
	mlx_hook(main.window, 17, 0, &cross, &main);
	display(&main);
	mlx_loop(main.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:41:26 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/24 16:43:47 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_main	main;

	if (argc != 2)
		ft_errors("Usage: ./cub3d map.cub");
	map_parser(argv[1], &main);
	main.mlx = mlx_init();
	mlx_loop(main.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:26:48 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 18:13:59 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_main	main;

	if (argc != 2)
		ft_errors("Usage: ./cub3d map.cub");
	map_render(argv[1], &main);
	if (!main.map)
		ft_errors("NULL map");
	for (int i = 0;main.map[i]; i++)
		printf("%s", main.map[i]);
	return (0);
}

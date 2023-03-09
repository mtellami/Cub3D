/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:53:02 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 18:29:27 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(char **map, double x, double y)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (map[size])
		size++;
	j = floor(x / TILE_SIZE);
	i = floor(y / TILE_SIZE);
	if (i < 0 || i >= size || j < 0 || j >= ft_strlen(map[i]))
		return (1);
	return (map[i][j] == '1');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:57:14 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 18:12:32 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(char *path)
{
	char	**map;
	char	*buffer;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_errors("Error: can't open the map");
	map = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		map = ft_concate(map, buffer);
		free(buffer);
	}
	close(fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:41:38 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:56 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_render(char *path, t_main *main)
{
	if (ft_strcmp(path + ft_strlen(path) - 4, ".cub")
			|| ft_strlen(path) < 5)
		ft_errors("Error: invalid map extention (.cub)");
	main->map = read_map(path);
}

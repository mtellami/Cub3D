/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:23:24 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 16:01:40 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef define
# define CUB3D

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>

typedef struct s_main
{
	char **map;
}	t_main;

/* ---------- Libft ---------- */
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_dprintf(int fd, char *str, ...);
void	ft_errors(char *err);

/* ---------- Src ---------- */
void map_render(char *path, t_main *main);

#endif
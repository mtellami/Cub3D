/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:23:24 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 17:58:43 by mtellami         ###   ########.fr       */
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

# define MALLOC_ERR "Error: can't allocate region"

typedef struct s_main
{
	char **map;
}	t_main;

/* ---------- Libft ---------- */
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_dprintf(int fd, char *str, ...);
void	ft_errors(char *err);
void	ft_free(char **tab);
char	**ft_concate(char **tab, char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);

/* ---------- Gnl ---------- */
int		ft_strnewin(char *str);
char	*ft_stradd(char *s1, char *s2);
char	*get_next_line(int fd);

/* ---------- Src ---------- */
void 	map_render(char *path, t_main *main);
char	**read_map(char *path);

#endif
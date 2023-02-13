/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:11:41 by mtellami          #+#    #+#             */
/*   Updated: 2023/02/13 18:12:22 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_concate(char **tab, char *str)
{
	char	**buffer;
	int		i;

	if (!tab)
	{
		tab = malloc(sizeof(char *));
		*tab = NULL;
	}
	buffer = malloc(sizeof(char *) * (ft_tabsize(tab) + 2));
	if (!buffer)
		ft_errors(MALLOC_ERR);
	i = -1;
	while (tab[++i])
		buffer[i] = ft_strdup(tab[i]);
	buffer[i++] = ft_strdup(str);
	buffer[i] = NULL;
	ft_free(tab);
	return (buffer);
}

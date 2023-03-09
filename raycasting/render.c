/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:37:58 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 21:54:17 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_ceil(t_main *main, int top_pixel, int i)
{
	int	j;

	j = 0;
	while (j < top_pixel)
		ft_mlx_pixel_put(&main->img, i, j++, rgb_color(main->map._ceil));
}

void	render_floor(t_main *main, int bottom_pixel, int i)
{
	int	j;

	j = bottom_pixel;
	while (j < WINDOW_HEIGHT)
		ft_mlx_pixel_put(&main->img, i, j++, rgb_color(main->map._floor));
}

void	render(t_main *main)
{
	int	top_pixel;
	int	bottom_pixel;
	int	i;

	main->img.img = mlx_new_image(main->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!main->img.img)
		ft_errors("fail creating mlx image");
	main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel,
			&main->img.line_length, &main->img.endian);
	i = 0;
	while (i < NUM_RAYS)
	{
		top_pixel = wall_top_pixel(main, i);
		bottom_pixel = wall_bottom_pixel(main, i);
		render_ceil(main, top_pixel, i);
		render_wall(main, top_pixel, bottom_pixel, i);
		render_floor(main, bottom_pixel, i);
		i++;
	}
	mlx_put_image_to_window(main->mlx, main->window, main->img.img, 0, 0);
	free(main->player.rays);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:37:34 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/09 21:09:00 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	horizontal_distance(t_main *main, t_vector horizontal_hit)
{
	double	horz_hit_distance;

	if (horizontal_hit.x != -1 && horizontal_hit.y != -1)
		horz_hit_distance = distance(main->player.vector, horizontal_hit);
	else
		horz_hit_distance = INT_MAX;
	return (horz_hit_distance);
}

double	vertical_distance(t_main *main, t_vector vertical_hit)
{
	double	vert_hit_distance;

	if (vertical_hit.x != -1 && vertical_hit.y != -1)
		vert_hit_distance = _distance(main->player.vector, vertical_hit);
	else
		vert_hit_distance = INT_MAX;
	return (vert_hit_distance);
}

void	setup_ray(t_main *main, t_ray *ray,
t_vector horizontal_hit, t_vector vertical_hit)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	horz_hit_distance = horizontal_distance(main, horizontal_hit);
	vert_hit_distance = vertical_distance(main, vertical_hit);
	if (vert_hit_distance < horz_hit_distance)
	{
		ray->x_wall_hit = vertical_hit.x;
		ray->y_wall_hit = vertical_hit.y;
		ray->distance = vert_hit_distance;
		ray->hit_side = VERTICAL_HIT;
	}
	else
	{
		ray->x_wall_hit = horizontal_hit.x;
		ray->y_wall_hit = horizontal_hit.y;
		ray->distance = horz_hit_distance;
		ray->hit_side = HORIZONTAL_HIT;
	}
}

t_ray	cast_ray(t_main *main, double ray_angle)
{
	t_ray		ray;
	t_vector	horizontal_hit;
	t_vector	vertical_hit;

	ray.angle = _angle(ray_angle);
	horizontal_hit = horizontal_raycast(main, ray_angle);
	vertical_hit = vertical_raycast(main, ray_angle);
	setup_ray(main, &ray, horizontal_hit, vertical_hit);
	return (ray);
}

void	raycasting(t_main *main)
{
	double	ray_angle;
	int		i;

	ray_angle = main->player.angle - (main->player.fov / 2);
	main->player.rays = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!main->player.rays)
		exit(1);
	i = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = _angle(ray_angle);
		main->player.rays[i] = cast_ray(main, ray_angle);
		ray_angle += main->player.fov / NUM_RAYS;
		i++;
	}
}

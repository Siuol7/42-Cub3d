/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:35:40 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 11:46:36 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rc_ver_point(t_ray *ray)
{
	double	delta_x;
	double	delta_y;

	ray->end.x = ray->hit_cell.col * CELL_PX;
	if (ray->end.x < ray->start.x)
		ray->end.x += CELL_PX;
	delta_x = ray->end.x - ray->start.x;
	delta_y = fabs(delta_x * tan(ray->angle));
	if (ray->dir.y > 0)
		ray->end.y = ray->start.y - delta_y;
	else
		ray->end.y = ray->start.y + delta_y;
}

static void	rc_ver_img(t_ray *ray, t_cub *cub)
{
	if (ray->end.x > ray->start.x)
		ray->image = cub->assets.wall[WE];
	else
		ray->image = cub->assets.wall[EA];
	ray->im_pos = fmod(ray->end.y, CELL_PX) * ray->image->width / CELL_PX;
}

static void	rc_hor_point(t_ray *ray)
{
	double	delta_x;
	double	delta_y;

	ray->end.y = ray->hit_cell.row * CELL_PX;
	if (ray->end.y < ray->start.y)
		ray->end.y += CELL_PX;
	delta_y = ray->end.y - ray->start.y;
	delta_x = fabs(delta_y / tan(ray->angle));
	if (ray->dir.x > 0)
		ray->end.x = ray->start.x + delta_x;
	else
		ray->end.x = ray->start.x - delta_x;
}

static void	rc_hor_img(t_ray *ray, t_cub *cub)
{
	if (ray->end.y < ray->start.y)
		ray->image = cub->assets.wall[SO];
	else
		ray->image = cub->assets.wall[NO];
	ray->im_pos = fmod(ray->end.x, CELL_PX) * ray->image->width / CELL_PX;
}

void	rc_process(t_ray *ray, t_cub *cub)
{
	if (ray->hit_dir == VER)
	{
		rc_ver_point(ray);
		rc_ver_img(ray, cub);
	}
	else
	{
		rc_hor_point(ray);
		rc_hor_img(ray, cub);
	}
	if (fpclassify(ray->dir.x) == FP_ZERO)
		ray->distance = fabs(ray->end.y - ray->start.y);
	else
		ray->distance = fabs((ray->end.x - ray->start.x) / ray->dir.x);
	ray->distance *= fabs(cos(move_angle_rescale(cub->player.angle
					- ray->angle)));
}

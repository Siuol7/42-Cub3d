/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_hit_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:35:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/06 20:27:00 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rc_init(t_distance *distance, t_point *step, t_ray *ray)
{
	t_dpoint	cur;

	cur = (t_dpoint){fmod(ray->start.x, CELL_PX), fmod(ray->start.y, CELL_PX)};
	*distance = (t_distance){DBL_MAX, DBL_MAX};
	*step = (t_point){1, 1};
	if (ray->dir.x > 0)
		distance->ver_line = fabs((CELL_PX - cur.x) / ray->dir.x);
	else if (ray->dir.x < 0)
	{
		distance->ver_line = fabs(cur.x / ray->dir.x);
		step->col = -1;
	}
	if (ray->dir.y > 0)
	{
		distance->hor_line = fabs(cur.y / ray->dir.y);
		step->row = -1;
	}
	else if (ray->dir.y < 0)
		distance->hor_line = fabs((CELL_PX - cur.y) / ray->dir.y);
}

void	rc_hit_point(t_ray *ray, t_cub *c)
{
	t_distance	distance;
	t_point		step;

	rc_init(&distance, &step, ray);
	while (c->map.grid[ray->hit_cell.row][ray->hit_cell.col] != '1')
	{
		if (distance.ver_line < distance.hor_line)
		{
			distance.ver_line += fabs(CELL_PX / ray->dir.x);
			ray->hit_cell.col += step.col;
			ray->hit_dir = VER;
		}
		else
		{
			distance.hor_line += fabs(CELL_PX / ray->dir.y);
			ray->hit_cell.row += step.row;
			ray->hit_dir = HOR;
		}
	}
}
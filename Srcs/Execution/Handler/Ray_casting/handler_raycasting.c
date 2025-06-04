/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:04:39 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/04 17:32:20 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static double	rc_angle(double angle, double i)
{
	return (move_angle_rescale(angle + (PI / 3) *
			(0.5 - i / (WIDTH - 1))));
}

static void	rc_ray_init(t_ray *ray, t_player player, int i)
{
	int	offset;

	offset = M_PLAYER_SIZE / 2;
	ray->angle = rc_angle(player.angle, (double)i);
	ray->dir = (t_dpoint){cos(ray->angle), sin(ray->angle)};
	ray->start = (t_dpoint){player.current.x + offset,
				player.current.y + offset};
	ray->end = (t_dpoint){ray->start.x, ray->start.y};
	ray->hit = (t_point){ray->start.y / CELL_PX, ray->start.x / CELL_PX};
}

void	handler_raycasting(t_cub *c)
{
	int		i;

	i = -1;
	if (!c || !c->rays)
		return ;
	while (++i < WIDTH)
	{
		ft_bzero(c->rays[i], sizeof(t_ray));
		rc_ray_init(c->rays[i], c->player, i);
		rc_hit_point(c->rays[i], c);
		rc_process(c->rays[i], c);
	}
}
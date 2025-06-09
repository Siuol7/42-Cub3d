/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:45:25 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 12:20:17 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_cub *c)
{
	int	i;

	i = 0;
	c->rays = (t_ray **)ft_calloc(WIDTH, sizeof(t_ray *));
	if (!c->rays)
		cub3d_ends(c, "Ray : allocating failed", 0);
	while (i < WIDTH)
	{
		c->rays[i] = (t_ray *)ft_calloc(1, sizeof(t_ray));
		if (!c->rays[i])
			cub3d_ends(c, "Ray : allocating failed", 0);
		i++;
	}
}

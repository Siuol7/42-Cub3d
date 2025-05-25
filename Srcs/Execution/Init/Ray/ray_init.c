/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:45:25 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/25 11:22:26 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_cub *c)
{
	int index;

	index = 0;
	c->rays =  (t_array**)ft_calloc(WIDTH, sizeof(t_ray*));
	if (!c->rays)
		clean_exec(c);
	while (index < WIDTH)
	{
		c->rays[index] = (t_ray*)ft_calloc(1, sizeof(t_ray));
		if (!c->rays[index])
			clean_exec(c);
		i++;
	}
}

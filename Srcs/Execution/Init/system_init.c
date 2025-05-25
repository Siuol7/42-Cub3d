/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:15:21 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/25 11:22:12 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mlx_packs_init(t_cub *c)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	c->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (c->mlx)
		clean_exec(c);
}

void	system_init(t_cub *c)
{
	mlx_packs_init(c);
	ray_init(c);
	asset_init(c);
	hook_init(c);
}
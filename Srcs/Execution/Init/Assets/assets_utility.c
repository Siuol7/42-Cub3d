/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:33:05 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/30 20:59:38 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assets_frame(t_cub *c, mlx_image_t **img, uint32_t w,	uint32_t h)
{
	*img = mlx_new_image(c->mlx, width, height);
	if (!*img)
		cub3d_ends(c, "am_init: mlx_new_image");
}

void	assets_framing(t_cub *c, t_assets *as)
{
	assets_frame(c, &am->ceiling, WIDTH, HEIGHT / 2);
	assets_frame(c, &am->floor, WIDTH, HEIGHT / 2);
	assets_frame(c, &am->scene, WIDTH, HEIGHT);
	assets_frame(c, &am->map, c->map.width, c->map.height);
	assets_frame(c, &am->m_map, M_WIDTH, M_HEIGHT);
	assets_frame(c, &am->m_wall, CELL_PX, CELL_PX);
	assets_frame(c, &am->m_player, CELL_PX, CELL_PX);
	assets_frame(c, &am->m_space, CELL_PX, CELL_PX);
	assets_frame(c, &am->m_map_bg, M_WIDTH, M_HEIGHT);
}


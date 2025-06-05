/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:33:05 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 09:31:25 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assets_frame(t_cub *c, mlx_image_t **img, uint32_t w,	uint32_t h)
{
	*img = mlx_new_image(c->mlx, w, h);
	if (!*img)
		cub3d_ends(c, "Assets init: mlx_new_image", 0);
}

void	assets_framing(t_cub *c, t_assets *as)
{
	assets_frame(c, &as->ceiling, WIDTH, HEIGHT / 2);
	assets_frame(c, &as->floor, WIDTH, HEIGHT / 2);
	assets_frame(c, &as->scene, WIDTH, HEIGHT);
	assets_frame(c, &as->canvas, c->map.width, c->map.height);
	assets_frame(c, &as->m_map, M_WIDTH, M_HEIGHT);
	assets_frame(c, &as->m_wall, CELL_PX, CELL_PX);
	assets_frame(c, &as->m_player, M_PLAYER_SIZE, M_PLAYER_SIZE);
	assets_frame(c, &as->m_space, CELL_PX, CELL_PX);
	assets_frame(c, &as->m_map_bg, M_WIDTH, M_HEIGHT);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:25:02 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 15:04:45 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_to_windows(t_cub *c, mlx_image_t *img,
	int32_t x, int32_t y)
{
	if (mlx_image_to_window(c->mlx, img, x, y) < 0)
		cub3d_ends(c, "mlx_image_to_window", EXIT_FAILURE);
}

void	display(t_cub *c)
{
	t_assets	*as;

	as = &c->assets;
	display_to_windows(c, as->ceiling, 0, 0);
	display_to_windows(c, as->floor, 0, HEIGHT / 2);
	display_to_windows(c, as->scene, 0, 0);
	display_to_windows(c, as->m_map_bg, M_OFFSET, M_OFFSET);
	display_to_windows(c, as->m_map, M_OFFSET, M_OFFSET);
	display_to_windows(c, as->player, WIDTH / 2 - (as->player->width / 2),
		HEIGHT - as->player->height + 405);
}
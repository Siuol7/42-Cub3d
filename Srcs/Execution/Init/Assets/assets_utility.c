/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:33:05 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/30 00:17:22 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assets_framing(t_cub *c, mlx_image_t **img, uint32_t w,	uint32_t h)
{
	*img = mlx_new_image(c->mlx, width, height);
	if (!*img)
		cub3d_ends(c, "am_init: mlx_new_image");
}
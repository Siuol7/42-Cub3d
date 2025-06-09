/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:40:52 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 12:17:34 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_cub *c)
{
	t_sprite *const	sprite = c->assets.sprite;
	mlx_image_t		*player;

	player = c->assets.player;
	render_px_cpy(c->assets.player, sprite->frame[sprite->frame_id],
		player->width, player->height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:55:17 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 23:04:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sprite(t_cub *c, t_sprite *sprite, double elapsed_time)
{
	if (!c->sprite.attack)
		return ;
	sprite->elapsed_time += elapsed_time;
	if (sprite->elapsed_time >= FRAME_INTERVAL)
	{
		sprite->frame_id++;
		sprite->elapsed_time -= FRAME_INTERVAL;
	}
	if (sprite->frame_id >= sprite->frame)
	{
		sprite->frame_id = 0;
		c->sprite.attack = 0;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 22:55:17 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 12:33:25 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_sprite(t_cub *c, t_sprite *sprite, double elapsed_time)
{
	if (!c->player.attack)
		return ;
	sprite->elapsed_time += elapsed_time;
	if (sprite->elapsed_time >= 0.1)
	{
		sprite->frame_id++;
		sprite->elapsed_time -= 0.1;
	}
	if (sprite->frame_id >= sprite->frame_cnt)
	{
		sprite->frame_id = 0;
		c->player.attack = 0;
	}
}
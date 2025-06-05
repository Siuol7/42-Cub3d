/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:10:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 23:06:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position(t_cub *c)
{
	t_player	*player;

	player = &c->player;
	if (position_validate(c, player->cur_pos.x, player->prev_pos.y))
		position_back_x(player, player->cur_pos.x);
	if (position_validate(c, player->prev_pos.x, player->cur_pos.y))
		position_back_y(player, player->cur_pos.y);
	if (position_validate(c, player->cur_pos.x, player->cur_pos.y))
	{
		position_back_x(player, player->cur_pos.x);
		position_back_y(player, player->cur_pos.y);
	}
}

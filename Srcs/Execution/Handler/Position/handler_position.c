/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:10:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/03 19:14:00 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position(t_cub *c)
{
	t_player	*player;

	player = &c->player;
	if (position_validate(c, player->current.x, player->prev.y))
		position_back_x(player, player->current.x);
	if (position_validate(c, player->prev.x, player->current.y))
		position_back_y(player, player->current.y);
	if (position_validate(c, player->current.x, player->current.y))
	{
		position_back_x(player, player->current.x);
		position_back_y(player, player->current.y);
	}
}

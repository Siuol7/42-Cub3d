/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:10:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/03 19:09:13 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position(t_cub *c)
{
	t_player	*player;

	player = &c->player;
	if (position_validate(c, player->current.x, player->prev.y))
		correct_x(player, player->current.x);
	if (position_validate(c, player->prev.x, player->current.y))
		correct_y(player, player->current.y);
	if (position_validate(c, player->current.x, player->current.y))
	{
		correct_x(player, player->current.x);
		correct_y(player, player->current.y);
	}
}
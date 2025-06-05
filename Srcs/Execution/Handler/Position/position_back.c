/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:09:33 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 23:13:14 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position_back_x(t_player *player, int x)
{
	const int32_t	col = x / CELL_PX;

	if (player->prev_pos.x > x)
		player->cur_pos.x = (col + 1) * CELL_PX;
	else if (player->prev_pos.x < x)
		player->cur_pos.x = (col + 1) * CELL_PX - 1 - M_PLAYER_SIZE;
}

void	position_back_y(t_player *player, int32_t y)
{
	const int32_t	row = y / CELL_PX;

	if (player->prev_pos.y > player->cur_pos.y)
		player->cur_pos.y = (row + 1) * CELL_PX;
	else if (player->prev_pos.y < player->cur_pos.y)
		player->cur_pos.y = (row + 1) * CELL_PX - 1 - M_PLAYER_SIZE;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_miniplayer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:40:25 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 12:18:35 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_miniplayer(t_cub *c, t_assets *as)
{
	uint8_t	*player_px;
	uint8_t	*map_org;
	uint8_t	*m_player_org;

	map_org = as->canvas->pixels;
	m_player_org = as->m_player->pixels;
	player_px = render_px_get(as->canvas, c->player.prev_pos.x,
			c->player.prev_pos.y);
	render_px_del(player_px, as->canvas->width, M_PLAYER_SIZE, M_PLAYER_SIZE);
	as->canvas->pixels = render_px_get(
			as->canvas, c->player.cur_pos.x, c->player.cur_pos.y);
	render_px_cpy(as->canvas, as->m_player, M_PLAYER_SIZE, M_PLAYER_SIZE);
	as->canvas->pixels = map_org;
	as->m_player->pixels = m_player_org;
}

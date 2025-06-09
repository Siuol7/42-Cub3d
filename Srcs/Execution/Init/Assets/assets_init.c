/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:02:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 12:23:09 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assets_sprite(t_cub *c, t_assets *as)
{
	as->sprite = assets_sprite_frame(c, 4, (t_resized){0, 0, 0}, SPRITE);
	assets_sprite_framing(c, as);
}

static void	assets_wall(t_cub *c, t_assets *as)
{
	as->wall[NO] = assets_graphic(c,
			(t_resized){0, CELL_PX, CELL_PX}, c->map.no);
	as->wall[SO] = assets_graphic(c,
			(t_resized){0, CELL_PX, CELL_PX}, c->map.so);
	as->wall[EA] = assets_graphic(c,
			(t_resized){0, CELL_PX, CELL_PX}, c->map.ea);
	as->wall[WE] = assets_graphic(c,
			(t_resized){0, CELL_PX, CELL_PX}, c->map.we);
}

static void	assets_main(t_cub *c, t_assets *as)
{
	assets_framing(c, as);
	assets_coloring(c, as);
}

void	assets_init(t_cub *c)
{
	t_assets	*assets;

	assets = &c->assets;
	assets_sprite(c, assets);
	assets_main(c, assets);
	assets_wall(c, assets);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:02:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/02 01:18:23 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assets_sprite(t_cub *c, t_assets *as)
{
	as->sprite = assets_sprite_frame(c, 5,
		(t_resized){0, 0, 0}, "./assets/sprite/stab.png");
	assets_sprite_framing(c, as);
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
	assets_main(c, assets);
	assets_sprite(c, assets);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:02:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/26 23:26:43 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assets_sprite(t_cub *c, t_assets *as)
{

}

static void	assets_mini(t_cub *c, t_assets *as)
{

}

static void	assets_main(t_cub *c, t_assets *as)
{

}

void	assets_init(t_cub *c)
{
	t_assets	*assets;

	assets = &c->assets;
	assets_main(c, assets);
	assets_mini(c, assets);
	assets_sprite(c, assets);
}

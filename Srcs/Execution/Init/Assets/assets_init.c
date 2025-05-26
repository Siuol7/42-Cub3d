/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:02:45 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/26 19:49:35 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assets_frame(t_cub *c, t_assets as)
{
	
}

void	assets_init(t_cub *c)
{
	t_assets	*assets;

	assets = &c->assets;
	assets_frame();
	assets_mini_frame();
	assets_sprite()
}

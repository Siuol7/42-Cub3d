/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:34 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 17:18:44 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_rays(t_cub *c)
{
	int i;

	if (!c->rays)
		return;
	i = 0;
	while (i < WIDTH)
		free(c->rays[i++]);
	free(c->rays);
	c->rays = NULL;
}

static void	clean_sprite(t_cub *c, t_assets *as)
{
	uint32_t	i;

	i = 0;
	if (!as->sprite)
		return ;
	while (i < as->sprite->frame_cnt)
	{
		if (as->sprite->frame[i])
			mlx_delete_image(c->mlx, as->sprite->frame[i]);
		i++;
	}
	if (as->sprite->sprite_sheet)
		mlx_delete_image(c->mlx, as->sprite->sprite_sheet);
	free(as->sprite->frame);
	free(as->sprite);
}

static void	clean_png(t_cub *c, t_assets *as)
{
	if (as->wall[NO])
		mlx_delete_image(c->mlx, as->wall[NO]);
	if (as->wall[SO])
		mlx_delete_image(c->mlx, as->wall[SO]);
	if (as->wall[WE])
		mlx_delete_image(c->mlx, as->wall[WE]);
	if (as->wall[EA])
		mlx_delete_image(c->mlx, as->wall[EA]);
}

static void	clean_draw(t_cub *c, t_assets *as)
{
	if (as->player)
		mlx_delete_image(c->mlx, as->player);
	if (as->ceiling)
		mlx_delete_image(c->mlx, as->ceiling);
	if (as->floor)
		mlx_delete_image(c->mlx, as->floor);
	if (as->scene)
		mlx_delete_image(c->mlx, as->scene);
	if (as->canvas)
		mlx_delete_image(c->mlx, as->canvas);
	if (as->m_map)
		mlx_delete_image(c->mlx, as->m_map);
	if (as->m_wall)
		mlx_delete_image(c->mlx, as->m_wall);
	if (as->m_player)
		mlx_delete_image(c->mlx, as->m_player);
	if (as->m_space)
		mlx_delete_image(c->mlx, as->m_space);
	if (as->m_map_bg)
		mlx_delete_image(c->mlx, as->m_map_bg);
}

void	clean_assets(t_cub *c, t_assets *as)
{
	if (!c || !as)
		return ;
	clean_draw(c, as);
	clean_png(c, as);
	clean_sprite(c, as);
	clean_rays(c);
}

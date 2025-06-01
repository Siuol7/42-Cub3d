/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:08:50 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/02 01:39:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assets_sprite_framing(t_cub *c, t_assets *as)
{
	int	i;

	i = 0;
	size = as->sprite->frame_size;
	while (i < size)
	{

	}
}

t_sprite	*assets_sprite_frame(t_cub *c,int size,	t_resized status,
	char *png_src)
{
	mlx_image_t	*img;
	t_sprite	*sprite;

	if (!c || !c->mlx || !png_src)
		cub3d_ends(c, "Sprite load: Invalid parameter(s)\n");
	img = assets_graphic(c, status, png_src);
	if (!img)
		cub3d_endsror("Sprite load: Loading graphic failed\n");
	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		cub3d_ends(c, "Sprite framing failed\n");
	sprite->sprite_w = img.
	sprite->frame_size = size;
	sprite->frame = (mlx_image_t **)ft_calloc(size, sizeof(mlx_image_t*));
	if (!sprite->frame)
		cub3d_ends("Sprite frame: Allocating failed\n");
	return (sprite);
}

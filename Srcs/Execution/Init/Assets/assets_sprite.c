/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:08:50 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 12:22:41 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assets_pixelcpy(mlx_image_t *src, mlx_image_t *dst,
							t_assets *as, int i)
{
	uint8_t		*src_pixel;
	uint8_t		*dst_pixel;
	uint32_t	w;
	uint32_t	h;
	uint32_t	y;

	y = 0;
	h = as->sprite->sprite_h;
	w = as->sprite->sprite_w;
	while (y < h)
	{
		src_pixel = &src->pixels[((y * src->width + i * w) * 4)];
		dst_pixel = &dst->pixels[(y * w) * 4];
		ft_memcpy(dst_pixel, src_pixel, w * 4);
		y++;
	}
}

void	assets_copy_paste(t_cub *c, t_assets *as, int i)
{
	mlx_image_t	*src;
	mlx_image_t	*dst;

	(void)c;
	src = as->sprite->sprite_sheet;
	dst = as->sprite->frame[i];
	assets_pixelcpy(src, dst, as, i);
}

void	assets_sprite_framing(t_cub *c, t_assets *as)
{
	uint32_t	i;

	i = 0;
	while (i < as->sprite->frame_cnt)
	{
		as->sprite->frame[i] = mlx_new_image(c->mlx,
				as->sprite->sprite_w, as->sprite->sprite_h);
		if (!as->sprite->frame[i])
			cub3d_ends(c, "Assets init: mlx_new_image", 0);
		assets_copy_paste(c, as, i);
		i++;
	}
}

t_sprite	*assets_sprite_frame(t_cub *c, int size, t_resized status,
	char *png_src)
{
	mlx_image_t	*img;
	t_sprite	*sprite;

	if (!c || !c->mlx || !png_src)
		cub3d_ends(c, "Sprite load: Invalid parameter(s)", 0);
	img = assets_graphic(c, status, png_src);
	if (!img)
		cub3d_ends(c, "Sprite load: Loading graphic failed", 0);
	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		cub3d_ends(c, "Sprite framing failed", 0);
	sprite->sprite_sheet = img;
	sprite->sprite_w = img->width / size;
	sprite->sprite_h = img->height;
	sprite->frame_cnt = size;
	sprite->frame = (mlx_image_t **)ft_calloc(size, sizeof(mlx_image_t *));
	if (!sprite->frame)
		cub3d_ends(c, "Sprite frame: Allocating failed", 0);
	return (sprite);
}

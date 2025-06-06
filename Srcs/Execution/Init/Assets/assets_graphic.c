/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:12:01 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/06 10:51:29 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t*	assets_graphic(t_cub *c, t_resized status, const char *png_src)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (!c->mlx)
	cub3d_ends(c, "MLX creating failed", 1);
	texture = mlx_load_png(png_src);
	if (!texture)
	{
		printf("%s\n", png_src);
		cub3d_ends(c, "Loading PNG failed", 1);
	}
	image = mlx_texture_to_image(c->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		cub3d_ends(c, "Loading texture to image failed", 1);
	if (status.resized)
	{
		if (!mlx_resize_image(image, status.rsz_x, status.rsz_y))
			cub3d_ends(c, "Resizing failed", 1);
	}
	return (image);
}

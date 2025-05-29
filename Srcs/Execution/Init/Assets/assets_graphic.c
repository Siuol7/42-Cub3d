/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_graphic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 01:12:01 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/28 09:25:48 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assets_framing(t_cub *c, mlx_image_t **img,	uint32_t w,	uint32_t h)
{
	*img = mlx_new_image(c->mlx, width, height);
	if (!*img)
		exec_error("am_init: mlx_new_image", c);
}

mlx_image_t*	assets_graphic(t_cub *c, t_resized status, const char *png_src)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (!c->mlx)
		exec_error(mlx_strerror(mlx_errno), c);
	texture = mlx_load_png(png_src);
	if (!texture)
		exec_error(mlx_strerror(mlx_errno), c);
	image = mlx_texture_to_image(c->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		exec_error(mlx_strerror(mlx_errno), c);
	if (status.resized)
	{
		if (!mlx_resize_image(image, status.rsz_x, status.rsz_y))
			exec_error(mlx_strerror(mlx_errno), c);
	}
	return (image);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:41:03 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:00 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	clear_image(mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	*pixels;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			pixels = (uint32_t *)(image->pixels + (y * image->width + x) * 4);
			*pixels = 0;
			x++;
		}
		y++;
	}
}

static void	copy_pixel(
	t_cub *c,
	int32_t x,
	int32_t y_pixel,
	int32_t image_pos_y
)
{
	uint32_t	*dest_pixels;
	uint32_t	*src_pixels;

	if ((uint8_t)image_pos_y < c->rays[x]->image->height - 1)
	{
		dest_pixels = (uint32_t *)ft_get_pixels(c->am.scene, x, y_pixel);
		src_pixels = (uint32_t *)ft_get_pixels(c->rays[x]->image,
				c->rays[x]->im_position,
				image_pos_y);
		*(uint32_t *)dest_pixels = *(uint32_t *)src_pixels;
	}
	else
	{
		dest_pixels = (uint32_t *)ft_get_pixels(c->am.scene, x, y_pixel);
		src_pixels = (uint32_t *)ft_get_pixels(c->rays[x]->image,
				c->rays[x]->im_position,
				c->rays[x]->image->height - 1);
		*(uint32_t *)dest_pixels = *(uint32_t *)src_pixels;
	}
}

static void	draw_texture(t_cub *c, int i, double wall_h,
				double scale)
{
	double		texture_y;
	int32_t		image_pos_y;
	int32_t		start_y;
	double		texture_offset;

	texture_offset = 0;
	if (wall_h >= HEIGHT)
	{
		texture_offset = (wall_h - HEIGHT) / -1.0;
		wall_h = HEIGHT - 1;
	}
	start_y = HEIGHT / 2 - wall_h / 2;
	texture_y = (start_y - HEIGHT / 2 + wall_h / 2) * scale
		* texture_offset;
	while (wall_h > 0)
	{
		image_pos_y = (int)texture_y;
		texture_y += scale;
		copy_pixel(c, i, start_y, image_pos_y);
		start_y++;
		wall_h--;
	}
}

void	render_scene(t_cub *c)
{
	int		i;
	double	wall_h;
	double	scale;
	double	dist_planecam;

	i = 0;
	dist_planecam = (WIDTH / 2) / tan(FOV / 2);
	clear_image(c->am.scene);
	while (i < WIDTH)
	{
		wall_h = (CELL_PX / c->rays[i]->distance) * dist_planecam;
		scale = (double)c->rays[i]->image->height / wall_h;
		draw_texture(c, i, wall_h, scale);
		i++;
	}
}
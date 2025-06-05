/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:11:48 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/04 22:13:53 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_px_cpy(mlx_image_t *dst,	mlx_image_t *src, int32_t copy_till_x,
									int32_t copy_till_y)
{
	int32_t		x;
	int32_t		y;
	uint32_t	*src_pixel;
	uint32_t	*dst_pixel;

	y = 0;
	while (y < copy_till_y)
	{
		x = 0;
		while (x < copy_till_x)
		{
			src_pixel = (uint32_t *) render_px_get(src, x, y);
			if (!src_pixel)
				return (0);
			dst_pixel = (uint32_t *) render_px_get(dst, x, y);
			if (!dst_pixel)
				return (0);
			*dst_pixel = *src_pixel;
			++x;
		}
		++y;
	}
	return (1);
}

void	render_px_del(uint8_t *start_px, uint32_t img_width, int32_t offset_x,
												int32_t offset_y)
{
	int32_t		x;
	int32_t		y;
	uint32_t	pos;
	uint32_t	*px;

	y = 0;
	while (y < offset_y)
	{
		x = 0;
		while (x < offset_x)
		{
			pos = (y * img_width + x) * sizeof(int32_t);
			px = (uint32_t *)(start_px + pos);
			*px = 0;
			++x;
		}
		++y;
	}
}

uint8_t	*render_px_get(mlx_image_t *img, int32_t x, int32_t y)
{
	int32_t	offset;

	if (x < 0 || (uint32_t)x >= img->width
		|| y < 0 || (uint32_t)y >= img->height)
	{
		ft_printf_fd(
			2, "ft_get_pixels: out of bounds [x=%d, y=%d] [w=%d, h=%d]\n",
			x, y, img->width, img->height);
		return (NULL);
	}
	offset = (y * img->width + x) * sizeof(int32_t);
	return (img->pixels + offset);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:10:29 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 21:56:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	assets_color_pallete(t_color color)
{
	return (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
}

static void	assets_color(mlx_image_t *img, int color)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, (unsigned int) color);
			++x;
		}
		++y;
	}
}

static void	assets_default_color(mlx_image_t *img, t_color color)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color_int;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color_int = assets_color_pallete(color);
			mlx_put_pixel(img, x, y, color_int);
			++x;
		}
		++y;
	}
}

void	assets_coloring(t_cub *c, t_assets *as)
{
	assets_color(as->ceiling, c->map.c_color);
	assets_color(as->floor, c->map.f_color);
	assets_default_color(as->m_wall, (t_color){180, 180, 180, 255});
	assets_default_color(as->m_player, (t_color){245, 0, 0, 255});
	assets_default_color(as->m_space, (t_color){40, 40, 4, 255});
	assets_default_color(as->m_map_bg, (t_color){45, 52, 54, 255});
}

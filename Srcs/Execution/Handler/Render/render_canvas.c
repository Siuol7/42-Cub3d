/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 13:34:15 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 14:09:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_miniwall(t_cub *c, mlx_image_t *map_img, char ele)
{
	if (ele == '1')
	{
		if (!render_px_cpy(map_img, c->assets.m_wall, M_PIXEL, M_PIXEL))
			cub3d_ends(c, "Rendering miniwall failed", EXIT_FAILURE);
	}
}

void	render_canvas(t_cub *c, mlx_image_t *map_img, char **grid)
{
	uint8_t *const	original = map_img->pixels;
	int32_t			row;
	int32_t			col;

	row = 0;
	while (row < c->map.max_rows)
	{
		col = 0;
		while (col < c->map.max_cols)
		{
			map_img->pixels = render_px_get(map_img, col * M_PIXEL,
													row * M_PIXEL);
			if (!map_img->pixels)
				cub3d_ends(c, "Rendering canvas failed", EXIT_FAILURE);
			render_miniwall(c, map_img, grid[row][col]);
			map_img->pixels = original;
			col++;
		}
		row++;
	}
}
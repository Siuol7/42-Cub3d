/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:40:40 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 23:29:45 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	max_point(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	render_x(t_cub *c, int32_t *x, int32_t *offset_x)
{
	int32_t	start_x;

	*offset_x = M_WIDTH;
	start_x = c->player.cur_pos.x - (M_WIDTH / 2);
	*x = max_point(start_x, 0);
	if (*x + M_WIDTH > c->map.width)
	{
		*x = max_point(c->map.width - M_WIDTH, 0);
		if (*x == 0)
			*offset_x = c->map.width;
	}
}

static void	render_y(t_cub *c, int32_t *y, int32_t *offset_y)
{
	int32_t	start_y;

	*offset_y = M_HEIGHT;
	start_y = c->player.cur_pos.y - (M_HEIGHT / 2);
	*y = max_point(start_y, 0);
	if (*y + M_HEIGHT > c->map.height)
	{
		*y = max_point(c->map.height - M_HEIGHT, 0);
		if (*y == 0)
			*offset_y = c->map.height;
	}
}

void	render_minimap(t_cub *c)
{
	uint8_t	*original;
	int32_t	x;
	int32_t	y;
	int32_t	offset_x;
	int32_t	offset_y;

	original = c->assets.canvas->pixels;
	render_x(c, &x, &offset_x);
	render_y(c, &y, &offset_y);
	c->assets.canvas->pixels = render_px_get(c->assets.canvas, x, y);
	render_px_cpy(c->assets.m_map, c->assets.canvas, offset_x, offset_y);
	c->assets.canvas->pixels = original;
}

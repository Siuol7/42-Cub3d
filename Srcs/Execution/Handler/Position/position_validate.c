/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:14:47 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/03 19:19:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	position_validation(t_cub *c, int32_t x, int32_t y)
{
	int32_t	row;
	int32_t	col;

	if (x < 0 || x >= c->map.width || y < 0 || y >= c->map.height)
		return (0);
	row = y / CELL_PX;
	col = x / CELL_PX;
	if (c->map.grid[row][col] == '1')
		return (0);
	return (1);
}

int	position_validate(t_cub *c, int x, int32_t y)
{
	if (!position_validation(c, x, y)
		|| !position_validation(c, x + M_PLAYER_SIZE, y)
		|| !position_validation(c, x, y + M_PLAYER_SIZE)
		|| !position_validation(c, x + M_PLAYER_SIZE, y + M_PLAYER_SIZE)
	)
		return (true);
	return (false);
}
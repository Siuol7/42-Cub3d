/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:26:50 by tripham           #+#    #+#             */
/*   Updated: 2025/05/26 19:39:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_dir(char c)
{
	if (c == 'N')
		return (PI / 2);
	else if (c == 'S')
		return (3 * PI / 2);
	else if (c == 'W')
		return (PI);
	else if (c == 'E')
		return (2 * PI);
	return (EXIT_SUCCESS);
}

static int	player_valid(t_cub *cub, int row)
{
	int	col;
	int	offset;

	col = 0;
	while (cub->map.grid[row][col])
	{
		if (!ft_strchr(" 01NSEW", cub->map.grid[row][col]))
			return (error_ret("Invalid character in map.", EXIT_FAILURE));
		else if (ft_strchr("NSEW", cub->map.grid[row][col]))
		{
			if (cub->player.angle > 0)
				return (error_ret("Must be 1 player.", EXIT_FAILURE));
			offset = (CELL_PX - M_PLAYER_SIZE) / 2;
			cub->player.prev_pos = (t_dpoint){col * CELL_PX, row * CELL_PX};
			cub->player.cur_pos.x = col * CELL_PX + offset;
			cub->player.cur_pos.y = row * CELL_PX + offset;
			cub->player.angle = get_dir(cub->map.grid[row][col]);
			cub->map.grid[row][col] = '0';
		}
		col++;
	}
	return (EXIT_SUCCESS);
}

int	grid_validate(t_cub *cub, int fd)
{
	int	row;

	row = 0;
	if (!dir_ele_done(&cub->map) || !cub->map.grid[0])
	{
		ft_error("Ivalid map.");
		return (map_err(&cub->map, NULL, fd));
	}
	while (*cub->map.grid && cub->map.grid[row])
	{
		if (player_valid(cub, row) == EXIT_FAILURE)
			return (map_err(&cub->map, NULL, fd));
		row++;
	}
	if (!cub->player.angle)
	{
		ft_error("Player not exist.");
		return (map_err(&cub->map, NULL, fd));
	}
	if (!is_closed(&cub->map, cub->player.cur_pos))
		return (map_err(&cub->map, NULL, fd));
	return (EXIT_SUCCESS);
}

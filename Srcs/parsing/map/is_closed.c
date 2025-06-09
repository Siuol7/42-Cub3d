/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:00:54 by tripham           #+#    #+#             */
/*   Updated: 2025/05/27 21:36:45 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**init_array(int row, int col)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)ft_calloc(row + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < row)
	{
		array[i] = (char *)ft_calloc(col + 1, sizeof(char));
		if (!array[i])
			return (ft_clean_2d(&array), NULL);
		ft_memset(array[i], ' ', col);
		i++;
	}
	return (array);
}

char	**assign_newgrid(t_map *map, int offset)
{
	int		row;
	int		col;
	char	**res;

	res = init_array(map->max_rows + 2 * offset, map->max_cols + 2 * offset);
	if (!res)
	{
		ft_error("ft_init_array");
		return (NULL);
	}
	row = -1;
	while (map && map->grid && map->grid[++row])
	{
		col = -1;
		while (map->grid[row][++col])
		{
			res[row + offset][col + offset] = map->grid[row][col];
		}
	}
	return (res);
}

static int	bloodfill_player(char **grid, int row, int col)
{
	if (row < 0 || col < 0 || !grid[row] || !grid[row][col]
		|| grid[row][col] == ' ')
		return (1);
	if (grid[row][col] == '1')
		return (0);
	grid[row][col] = '1';
	return (bloodfill_player(grid, row + 1, col)
		|| bloodfill_player(grid, row - 1, col)
		|| bloodfill_player(grid, row, col + 1)
		|| bloodfill_player(grid, row, col - 1));
}

static int	bloodfill_wall(char **grid, int row, int col)
{
	if (row < 0 || col < 0 || !grid[row] || !grid[row][col]
		|| grid[row][col] == '1')
		return (0);
	if (grid[row][col] == '0')
		return (1);
	grid[row][col] = '1';
	return (bloodfill_wall(grid, row + 1, col)
		|| bloodfill_wall(grid, row - 1, col)
		|| bloodfill_wall(grid, row, col + 1)
		|| bloodfill_wall(grid, row, col - 1));
}

bool	is_closed(t_map *map, t_dpoint pos)
{
	char	**tmp;
	int		x;
	int		y;

	y = (int)(pos.y / CELL_PX) + 1;
	x = (int)(pos.x / CELL_PX) + 1;
	tmp = assign_newgrid(map, 1);
	if (!tmp)
		return (error_ret("assign_newgrid failed", false));
	if (bloodfill_player(tmp, y, x) || bloodfill_wall(tmp, 0, 0))
		return (ft_clean_2d(&tmp), error_ret("Map is unclosed by walls.",
				false));
	ft_clean_2d(&tmp);
	tmp = assign_newgrid(map, 0);
	if (!tmp)
		return (error_ret("assign_newgrid failed (clean)", false));
	ft_clean_2d(&map->grid);
	map->grid = tmp;
	return (true);
}

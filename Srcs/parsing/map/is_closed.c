/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:00:54 by tripham           #+#    #+#             */
/*   Updated: 2025/05/24 18:13:21 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**init_array(int rows, int cols)
{
	char	**array = (char **)ft_calloc(rows + 1, sizeof(char *));
	int		i;

	if (!array)
		return (NULL);
	for (i = 0; i < rows; i++)
	{
		array[i] = (char *)ft_calloc(cols + 1, sizeof(char));
		if (!array[i])
			return (ft_clean_array(&array), NULL);
		ft_memset(array[i], ' ', cols);
	}
	return (array);
}

static char	**assign_newgrid(t_map *map, int offset)
{
	char	**res = init_array(map->max_rows + 2 * offset, map->max_cols + 2 * offset);
	int		row, col;

	if (!res)
		return (ft_error("assign_newgrid: calloc failed"), NULL);
	for (row = 0; row < map->max_rows; row++)
		for (col = 0; map->grid[row][col]; col++)
			res[row + offset][col + offset] = map->grid[row][col];
	return (res);
}

static int	flood_fill(char **grid, int row, int col, int mode)
{
	if (row < 0 || col < 0 || !grid[row] || !grid[row][col])
		return (mode == 0);
	if (grid[row][col] == '1' || grid[row][col] == ' ')
		return (0);
	if (mode == 1 && grid[row][col] == '0')
		grid[row][col] = '1';
	else if (mode == 0 && grid[row][col] == '0')
		return (1);

	grid[row][col] = '1';
	return (flood_fill(grid, row + 1, col, mode)
		|| flood_fill(grid, row - 1, col, mode)
		|| flood_fill(grid, row, col + 1, mode)
		|| flood_fill(grid, row, col - 1, mode));
}

bool	is_closed(t_map *map, t_dpoint start)
{
	char	**temp;

	temp = assign_newgrid(map, 1);
	if (!temp)
		return (ft_error_ret("assign_newgrid failed", false));

	int y = (int)(start.y / CELL_PX) + 1;
	int x = (int)(start.x / CELL_PX) + 1;

	if (flood_fill(temp, y, x, 1) || flood_fill(temp, 0, 0, 0))
	{
		ft_clean_array(&temp);
		return (ft_error_ret("Map is unclosed by walls.", false));
	}
	ft_clean_array(&map->grid);
	map->grid = assign_newgrid(map, 0);
	if (!map->grid)
		return (ft_error_ret("assign_newgrid failed (clean version)", false));

	return (true);
}

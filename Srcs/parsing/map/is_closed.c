/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:00:54 by tripham           #+#    #+#             */
/*   Updated: 2025/05/26 19:37:52 by tripham          ###   ########.fr       */
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
	int		x;
	int		y;

	temp = assign_newgrid(map, 1);
	if (!temp)
		return (error_ret("assign_newgrid failed", false));
	y = (int)(start.y / CELL_PX) + 1;
	x = (int)(start.x / CELL_PX) + 1;
	if (flood_fill(temp, y, x, 1) || flood_fill(temp, 0, 0, 0))
	{
		ft_clean_2d(&temp);
		return (error_ret("Map is unclosed by walls.", false));
	}
	ft_clean_2d(&temp);
	temp = assign_newgrid(map, 0);
	if (!map->grid)
		return (error_ret("assign_newgrid failed", false));
	ft_clean_2d(&map->grid);
	map->grid = temp;
	return (true);
}

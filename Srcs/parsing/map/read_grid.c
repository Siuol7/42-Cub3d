/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:59:47 by tripham           #+#    #+#             */
/*   Updated: 2025/05/26 19:39:01 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Douple check new_grid[row][++col] = ' '; 
static int	grid_copied(char **new_grid, t_map *map)
{
	int	row;
	int	col;
	int	len;

	row = -1;
	if (!map || !map->grid)
		return (EXIT_FAILURE);
	while (map->grid[++row])
	{
		new_grid[row] = (char *)ft_calloc(map->max_cols + 1, sizeof(char));
		if (!new_grid[row])
			return (error_ret("Grid copy failed.", EXIT_FAILURE));
		col = -1;
		len = ft_strlen(map->grid[row]);
		while (++col < len && map->grid[row][col])
			new_grid[row][col] = map->grid[row][col];
		while (col < map->max_cols)
			new_grid[row][++col] = ' ';
	}
	return (EXIT_SUCCESS);
}

static int	map_allocated(t_map *map)
{
	char	**new_grid;

	if (map->max_rows >= map->size)
	{
		map->size += G_BUFFER;
		new_grid = (char **)ft_calloc(map->size + 1, sizeof(char *));
		if (!new_grid)
			return (EXIT_FAILURE);
		if (grid_copied(new_grid, map) == EXIT_FAILURE)
		{
			ft_clean_2d(&new_grid);
			return (EXIT_FAILURE);
		}
		ft_clean_2d(&map->grid);
	}
	return (EXIT_SUCCESS);
}

int	read_grid(t_map *map, char *line)
{
	int	len;

	if (!map || !line)
		return (EXIT_FAILURE);
	len = ft_strlen(line);
	if (map_allocated(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map->grid[map->max_rows] = ft_strdup(line);
	if (!map->grid[map->max_rows])
		return (error_ret("ft_strdup for map reading failed.", EXIT_FAILURE));
	if (len > map->max_cols)
		map->max_cols = len;
	map->max_rows++;
	return (EXIT_SUCCESS);
}

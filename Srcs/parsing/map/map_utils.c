/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:32:35 by tripham           #+#    #+#             */
/*   Updated: 2025/05/26 19:39:32 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	dir_ele_done(t_map *map)
{
	return (map->no && map->so && map->we && map->ea
		&& map->f_color && map->c_color);
}

int	map_err(t_map *map, char *line, int fd)
{
	clean_map(map);
	if (line)
		free(line);
	close (fd);
	return (EXIT_FAILURE);
}

int	cnt_comma(char *str)
{
	int	comma;

	comma = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == ',')
			comma++;
		str++;
	}
	return (comma);
}

void	clean_map(t_map *map)
{
	if (!map || !map->grid)
		return ;
	if (map->no)
		free_null(&map->no);
	if (map->so)
		free_null(&map->so);
	if (map->we)
		free_null(&map->we);
	if (map->ea)
		free_null(&map->ea);
	if (map->grid)
		ft_clean_2d(&map->grid);
}

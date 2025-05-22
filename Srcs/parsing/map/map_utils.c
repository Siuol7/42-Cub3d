/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:32:35 by tripham           #+#    #+#             */
/*   Updated: 2025/05/22 23:07:04 by tripham          ###   ########.fr       */
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
	(void)map;
	// clean_map(map);
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
	while(*str)
	{
		if (*str == ',')
			comma++;
		str++;
	}
	return (comma);
}

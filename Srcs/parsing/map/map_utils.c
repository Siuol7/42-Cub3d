/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:32:35 by tripham           #+#    #+#             */
/*   Updated: 2025/05/21 22:19:39 by tripham          ###   ########.fr       */
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

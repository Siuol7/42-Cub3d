/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:28:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/26 19:16:27 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(t_cub *cub, char *line)
{
	if (!dir_ele_done(&cub->map))
		return (read_ele(&cub->map, line));
	else
	{
		if (!line[0] && cub->map.grid && !cub->map.grid[0])
		{
			return (EXIT_SUCCESS);
		}
		else if (!line[0] && cub->map.grid && cub->map.grid[0])
			return (error_ret("Elements or map is invalid.", EXIT_FAILURE));
		return (read_grid(&cub->map, line));
	}
	return (EXIT_SUCCESS);
}

int	read_map(int fd, t_cub *cub)
{
	char	*line;
	int		eof;

	eof = 0;
	cub->map.size = G_BUFFER;
	cub->map.grid = (char **)ft_calloc(cub->map.size + 1, sizeof(char *));
	if (!cub->map.grid)
		return (error_ret("Map allocation failed.", 1));
	while (1)
	{
		line = ft_readline(fd, &eof);
		if (!line)
			return (EXIT_FAILURE);
		if (eof)
		{
			if (process_line(cub, line) == EXIT_FAILURE)
				return (map_err(&cub->map, line, fd));
			free(line);
			break ;
		}
		if (process_line(cub, line) == EXIT_FAILURE)
			return (map_err(&cub->map, line, fd));
		free(line);
	}
	return (grid_validate(cub, fd));
}

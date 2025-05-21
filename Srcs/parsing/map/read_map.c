/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:28:14 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/19 19:46:19 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(t_cub *cub, char *line)
{
	if (!dir_ele_done(&cub->map))
		return (read_ele(&cub->map, line));
	else
	{
		
	}
}

int	read_map(int fd, t_cub *cub)
{
	char 	*line;

	cub->map.size = G_BUFFER;
	cub->map.grid = (char **)ft_calloc(cub->map.size + 1, sizeof(char *));
	if (!cub->map.grid)
	{
		ft_printf_fd(2, "Error:\nMap malloc failed!\n");
		return (1);	
	}
	while ((line = get_next_line(fd)) != NULL)
    {
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';

		if (process_line(cub, line) == EXIT_FAILURE)
		{
			free(line);
			return map_error(&cub->map, line, fd);
		}
		free(line);
	}
	if (!line)
	{
		free(cub->map.grid);
		ft_printf_fd(2, "Error:\nEmpty map!\n");
		return (1);
	}
	return (grid_validation(cub, fd));
}

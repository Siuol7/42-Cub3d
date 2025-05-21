/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:49:40 by tripham           #+#    #+#             */
/*   Updated: 2025/05/18 22:52:22 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_validation(char *path)
{
	int fd;
	int i;

	if (!path || ft_is_all_white_spaces(path))
	{
		ft_printf_fd(2, "Error:\nInvalid map path!\n");
		return (-1);
	}
	i = ft_strlen(path);
	if (i < 5 || ft_strncmp(path + i - 4, ".cub", 4))
	{
		ft_printf_fd(2, "Error:\nInvalid .cub file!\n");
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(2, "Error:\nFailed to open file: %s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}

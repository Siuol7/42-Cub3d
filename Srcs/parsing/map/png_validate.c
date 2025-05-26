/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:24:40 by tripham           #+#    #+#             */
/*   Updated: 2025/05/26 18:52:38 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_real_png(char *path)
{
	int				fd;
	unsigned char	header[8];

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_ret(path, EXIT_FAILURE));
	if (read(fd, header, 8) != 8 || header[0] != 0x89 || header[1] != 0x50
		|| header[2] != 0x4E || header[3] != 0x47 || header[4] != 0x0D
		|| header[5] != 0x0A || header[6] != 0x1A || header[7] != 0x0A)
	{
		close(fd);
		return (multi_err_ret(path, "Invalid PNG file.", EXIT_FAILURE));
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	validate_png(char *path)
{
	int	len;

	if (!path || !path[0] || ft_is_all_white_spaces(path))
		return (multi_err_ret(path, "Path is empty", EXIT_FAILURE));
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".png", 4) != 0)
		return (multi_err_ret(path, "Invalid .png file format.", EXIT_FAILURE));
	if (access(path, F_OK) == -1)
		return (error_ret(path, EXIT_FAILURE));
	return (is_real_png(path));
}

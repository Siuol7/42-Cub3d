/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/21 20:16:44 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	if (ac != 2)
	{
		ft_printf_fd(2, "Error:\nWrong input!\n");
		return (EXIT_FAILURE);
	}
	ft_bzero(&cub, sizeof(t_cub));
	fd = map_validation(av[1]);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (read_map(fd, &cub))
	{
		close(fd);
		ft_printf_fd(2, "Error:\nFailed to read map!\n");
		return (EXIT_FAILURE);
	}
	exit(1);
}

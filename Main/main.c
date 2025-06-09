/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:55:42 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 22:04:33 by caonguye         ###   ########.fr       */
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
		return (EXIT_FAILURE);
	cub.map.width = cub.map.max_cols * M_PIXEL;
	cub.map.height = cub.map.max_rows * M_PIXEL;
	close(fd);
	system_init(&cub);
	mlx_loop(cub.mlx);
	cub3d_ends(&cub, "Done", 0);
	return (EXIT_SUCCESS);
}

	// printf("✅ Map parsed successfully!\n");

	// // In texture path
	// printf("NO: %s\n", cub.map.no);
	// printf("SO: %s\n", cub.map.so);
	// printf("WE: %s\n", cub.map.we);
	// printf("EA: %s\n", cub.map.ea);
	// printf("F : %d\n", cub.map.f_color);
	// printf("C : %d\n", cub.map.c_color);

	// // In player position (sau khi validate)
	// printf("Player pos: x = %.2f, y = %.2f, angle = %.2f\n",
	// 	cub.player.cur_pos.x,
	// 	cub.player.cur_pos.y,
	// 	cub.player.angle);

	// // In grid map
	// printf("Map grid:\n");
	// for (int i = 0; cub.map.grid[i]; i++)
	// 	printf("%s\n", cub.map.grid[i]);

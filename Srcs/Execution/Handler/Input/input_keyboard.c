/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:53:55 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 10:43:59 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	input_keyboard(t_cub *c)
{
	t_dpoint	cur_pos;

	cur_pos = c->player.cur_pos;
	c->player.prev_pos = c->player.cur_pos;
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		cub3d_ends(c, "Done", EXIT_SUCCESS);
	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
		c->player.cur_pos = move_dir(cur_pos, c->player.angle, MLX_KEY_W);
	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		c->player.cur_pos = move_dir(cur_pos, c->player.angle, MLX_KEY_A);
	if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		c->player.cur_pos = move_dir(cur_pos, c->player.angle, MLX_KEY_S);
	if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		c->player.cur_pos = move_dir(cur_pos, c->player.angle, MLX_KEY_D);
	if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
		c->player.angle = move_angle_rescale(c->player.angle + PI / 36);
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		c->player.angle = move_angle_rescale(c->player.angle - PI / 36);
}

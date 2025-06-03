/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:10:33 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/03 17:16:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	move_angle_rescale(double angle)
{
	if (angle < 0)
		return (angle + 2 * PI);
	else if (angle >= 2 * PI)
		return (angle - 2 * PI);
	else
		return (angle);
}

t_dpoint	move_dir(t_dpoint cur, double angle, keys_t key)
{
	t_dpoint	new_pos;

	new_pos = (t_dpoint){cur.x, cur.y};
	if (key == MLX_KEY_W)
	{
		new_pos = (t_dpoint){cur.x + cos(angle), cur.y - sin(angle)};
	}
	else if (key == MLX_KEY_S)
		new_pos = (t_dpoint){cur.x - cos(angle), cur.y + sin(angle)};
	else if (key == MLX_KEY_A)
		new_pos = (t_dpoint){cur.x + cos(angle + PI / 2),
			cur.y - sin(angle + PI / 2)};
	else if (key == MLX_KEY_D)
		new_pos = (t_dpoint){cur.x + cos(angle + 3 * PI / 2),
			cur.y - sin(angle + 3 * PI / 2)};
	return (new_pos);
}
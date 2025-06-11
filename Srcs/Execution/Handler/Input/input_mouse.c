/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:54:13 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/11 10:58:19 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	input_mousemove(t_cub *c)
{
	int32_t		new_x;
	int32_t		new_y;
	int32_t		delta_x;

	mlx_get_mouse_pos(c->mlx, &new_x, &new_y);
	delta_x = new_x - c->mouse_x;
	if (delta_x != 0)
		c->player.angle = move_angle_rescale(
				c->player.angle - delta_x * 0.003);
	c->mouse_x = new_x;
	c->mouse_y = new_y;
}

static void	input_mousehold(t_cub *c, double cur, double *last_atk, double cd)
{
	if (cur - *last_atk >= cd)
	{
		c->player.attack = 1;
		render_sprite(c, c->assets.sprite, c->mlx->delta_time);
		*last_atk = cur;
	}
}

static void	input_mouseclick(t_cub *c)
{
	static int		prev_status = 0;
	static double	last_atk = 0;
	double			cur;
	int				cur_status;
	double			cd;

	cur = mlx_get_time();
	cur_status = mlx_is_mouse_down(c->mlx, MLX_MOUSE_BUTTON_LEFT);
	cd = 0.3;
	if (cur_status && !prev_status)
	{
		c->player.attack = 1;
		render_sprite(c, c->assets.sprite, c->mlx->delta_time);
		last_atk = cur;
	}
	else if (cur_status && prev_status)
		input_mousehold(c, cur, &last_atk, cd);
	else if (!cur_status)
	{
		c->player.attack = 0;
		c->assets.sprite->frame_id = 0;
	}
	prev_status = cur_status;
}

void	input_mouse(t_cub *c)
{
	input_mousemove(c);
	input_mouseclick(c);
}

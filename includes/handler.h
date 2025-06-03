/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:35:22 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/03 19:20:03 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H

 #define HANDLER_H

#include "cub3d.h"

typedef struct s_cub	t_cub;
typedef struct s_assets t_assets;

void		handler_loop(void* data);
void		handler_close(void* data);
double		move_angle_rescale(double angle);
t_dpoint	move_dir(t_dpoint cur, double angle, keys_t key);

//INPUT
void		handler_input(t_cub* c);
void		input_keyboard(t_cub* c);
void		input_mouse(t_cub *c);
double		move_angle_rescale(double angle);
t_dpoint	move_dir(t_dpoint cur, double angle, keys_t key);

//POSITION
int			position_validate(t_cub *c, int x, int32_t y);
void		position(t_cub *c);
void		position_back_y(t_player *player, int32_t y);
void		position_back_x(t_player *player, int x);

#endif
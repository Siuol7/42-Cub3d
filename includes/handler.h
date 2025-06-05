/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:35:22 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 10:59:54 by caonguye         ###   ########.fr       */
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

//RAY CASTING

void		handler_raycasting(t_cub *c);
void		rc_hit_point(t_ray *ray, t_cub *cub);
void		rc_process(t_ray *ray, t_cub *cub);

//RENDER
void		render_miniplayer(t_cub *c, t_asset_manager *as);
uint8_t		*render_px_get(mlx_image_t *img, int32_t x, int32_t y);
int			render_px_cpy(mlx_image_t *dst,	mlx_image_t *src, int32_t copy_till_x,
									int32_t copy_till_y);
void		render_px_del(uint8_t *start_px, uint32_t img_width, int32_t offset_x,
									int32_t offset_y);
void		render_minimap(t_cub *c);
void		render_player(t_cub *c);
void		render_scene(t_cub *c);

#endif
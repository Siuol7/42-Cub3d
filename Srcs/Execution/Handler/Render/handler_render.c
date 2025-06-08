/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:27:15 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 14:56:51 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_render(t_cub *c)
{
	render_canvas(c, c->assets.canvas, c->map.grid);
	render_minimap(c);
	render_miniplayer(c, &c->assets);
	render_player(c);
	render_scene(c);
}
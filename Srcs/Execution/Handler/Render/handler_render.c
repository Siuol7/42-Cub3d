/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:27:15 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 13:32:54 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_render(t_cub *c)
{
	render_canvas(c);
	render_miniplayer(c, &c->assets);
	render_minimap(c);
	render_player(c);
	render_scene(c);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:34:46 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 23:37:46 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_loop(void* data)
{
	t_cub*	c;

	c = (t_cub*)data;
	handler_input(c);
	handler_position(c);
	handler_raycasting(c);
	handler_render(c);
}

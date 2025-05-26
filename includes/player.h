/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:38:48 by tripham           #+#    #+#             */
/*   Updated: 2025/05/26 19:39:43 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "utility.h"
# include "cub3d.h"

typedef struct s_cub	t_cub;
/*
    t_dpoint    pos;    // current position
    t_dpoint    prev;   // position before moving
    double      angle;  // viewing angle (in radians)
    double      speed;  // movement speed
	-> All info of a player/camera
*/
typedef struct s_player
{
	t_dpoint	cur_pos;
	t_dpoint	prev_pos;
	double		angle;
	double		speed;
	int			attack;
}	t_player;

#endif
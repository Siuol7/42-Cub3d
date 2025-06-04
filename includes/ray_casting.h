/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:54 by tripham           #+#    #+#             */
/*   Updated: 2025/06/04 18:02:55 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "cub3d.h"
# include "utility.h"

typedef struct s_cub	t_cub;

/*
*	HORIZONTAL,
*	VERTICAL
* -> Result of 1 ray in ray-casting
*/
typedef enum s_hit_dir
{
	HOR,
	VER,
}	t_hit_dir;

typedef struct s_distance
{
	double	hor_line;
	double	ver_line;
}	t_distance;

/*
 t_dpoint    start;      // starting position (player.pos)
    t_dpoint    hit_pos;    // actual collision point
    t_point     hit_cell;   // grid cell where the collision occurred
    double      distance;   // distance (fish-eye correction applied)
    t_hit_dir   hit_dir;    // direction of collision (horizontal or vertical)
    int         tex_id;     // texture ID (0–3 corresponding to NO, SO, WE, EA)
    int         tex_x;      // pixel offset within the texture
*/
typedef struct s_ray
{
	t_dpoint	start;
	t_dpoint	end;
	t_dpoint	dir;
	t_point		hit_cell;
	double		distance;
	double		angle;
	t_hit_dir	hit_dir;
	mlx_image_t	*image;
	int			im_pos;
}	t_ray;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/21 23:50:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # define WIDTH 1280
// # define HEIGHT 960
// # define PI 3.14159265359

# include <stdio.h>
//# include <float.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "map.h"
# include "player.h"
# include "ray_casting.h"
# include "utility.h"
# include "MLX42.h"

/* Complete application context
 void        *mlx;       // MLX42 context
    t_map        map;       // map data: textures and colors
    t_player     player;    // camera/player
    t_ray      **rays;      // array of ray pointers, length = screen_w
    //add asset manager, sprites, image buffer, etc.
*/
typedef struct s_cub
{
	mlx_t		*mlx;
	t_map		map;
	t_player	player;
	int32_t		mouse_x;
	int32_t		mouse_y;
	t_ray		**rays;
}	t_cub;

#endif
// # define FOV 1.04719755120
// # define CELL_PX 32
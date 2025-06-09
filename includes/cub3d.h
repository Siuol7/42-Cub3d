/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:56:04 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/08 22:04:06 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720
# define PI 3.14159265359
# define FOV 1.04719755120f
# define CELL_PX 32

# include <stdio.h>
# include <float.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "map.h"
# include "player.h"
# include "ray_casting.h"
# include "utility.h"
# include "MLX42.h"
# include "assets.h"
# include "error.h"
# include "handler.h"

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
	t_assets	assets;
}	t_cub;

void	system_init(t_cub *c);
void	cub3d_ends(t_cub* c, char *str, int exitcode);
void 	clean_assets(t_cub *c, t_assets *as);
void	display(t_cub *c);

#endif
// # define FOV 1.04719755120
// # define CELL_PX 32
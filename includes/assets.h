/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:53:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/05/26 20:01:38 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ASSETS_H

 #define	ASSETS_H

# define M_OFFSET	    10
# define M_PLAYER_SIZE	10
# define SPRITE			"./assets/sprites/stab.png"
# define M_SPACE		"./assets/textures/mini_space.png"
# define M_WALL			"./assets/textures/mini_wall.png"
# define M_PLAYER		"./assets/textures/mini_player.png"
# define M_WIDTH 		200
# define M_HEIGHT 		200

# include "utility.h"
# include "MLX42.h"

typedef struct s_cub	t_cub;

typedef struct s_resized
{
	int			resized;
	unint42_t	rsz_x;
	unint32_t	rsz_y;
}	t_resized;


typedef struct s_assets
{
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	mlx_image_t	*map;
	mlx_image_t	*scene;
	mlx_image_t	*m_wall;
	mlx_image_t	*m_floor;
	mlx_image_t	*m_player;
	mlx_image_t	*m_map;
	mlx_image_t	*m_txtr;
}	t_assets;


#endif
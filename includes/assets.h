/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:53:08 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/05 10:38:57 by caonguye         ###   ########.fr       */
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
# define SPRITE_TIME	0.4
# define FRAMES			5
# define FRAME_INTERVAL	(SPRITE_TIME / FRAMES)

# include "utility.h"
# include "MLX42.h"

typedef struct s_cub	t_cub;

typedef enum e_dir
{
	VERTICAL,
	HORIZONTAL
}	t_dir;

typedef struct	s_sprite
{
	mlx_image_t**	frame;
	mlx_image_t*	sprite_sheet;
	uint32_t		sprite_w;
	uint32_t		sprite_h;
	uint32_t		frame_id;
	int				frame_cnt;
	double			elapsed_time;
}	t_sprite;


typedef struct s_resized
{
	int			resized;
	uint32_t	rsz_x;
	uint32_t	rsz_y;
}	t_resized;

typedef struct s_assets
{
	t_sprite	*sprite;
	mlx_image_t	*player;
	mlx_image_t	*wall[4];
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	mlx_image_t	*canvas;
	mlx_image_t	*scene;
	mlx_image_t	*m_wall;
	mlx_image_t	*m_player;
	mlx_image_t	*m_map;
	mlx_image_t	*m_space;
	mlx_image_t	*m_map_bg;
}	t_assets;


void			ray_init(t_cub *c);
void			assets_init(t_cub *c);
void			assets_framing(t_cub *c, t_assets *as);
void			assets_frame(t_cub *c, mlx_image_t **img, uint32_t w,	uint32_t h);
void			assets_sprite_framing(t_cub *c, t_assets *as);
void			assets_copy_paste(t_cub *c, t_assets* as, int i);
void			assets_coloring(t_cub *c, t_assets *as);
t_sprite		*assets_sprite_frame(t_cub *c,int size,	t_resized status, char *png_src);
mlx_image_t*	assets_graphic(t_cub *c, t_resized status, const char *png_src);

#endif
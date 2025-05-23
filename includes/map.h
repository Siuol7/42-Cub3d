/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:37:22 by tripham           #+#    #+#             */
/*   Updated: 2025/05/23 19:22:18 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "utility.h"
# include "cub3d.h"

typedef struct s_cub	t_cub;

typedef enum e_ele_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_ele_type;

/*
*char   *no;   	        -> file path for the North wall texture
*char   *so;   	        -> file path for the South wall texture
*char   *we;   	        -> file path for the West wall texture
*char   *ea;   	        -> file path for the East wall texture
*char   **grid;     	-> 2D map array containing characters:
 '0', '1', 'N', 'S', 'E', 'W'
*int	f_color;    	-> floor color
*int	c_color;  	-> ceiling color
*int      width;    	-> number of columns in the map
*int      height;   	-> number of rows in the map
*-> All info of map + textures + color
*/
typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**grid;
	int			f_color;
	int			c_color;
	int			width;
	int			height;
	int			size;
	int			max_rows;
	int			max_cols;
}	t_map;

//void	read_map(char *map_file, t_map *map);
bool	dir_ele_done(t_map *map);
int		read_map(int fd, t_cub *cub);
int		read_ele(t_map *map, char *line);

// check valid png
int	validate_png(char *path);

#endif
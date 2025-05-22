/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ele.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:46:56 by tripham           #+#    #+#             */
/*   Updated: 2025/05/22 23:08:27 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ele_type_check(char *arr)
{
	if (!arr)
		return (-1);
	else if (!ft_strcmp(arr, "NO"))
		return (NO);
	else if (!ft_strcmp(arr, "SO"))
		return (SO);
	else if (!ft_strcmp(arr, "WE"))
		return (WE);
	else if (!ft_strcmp(arr, "EA"))
		return (EA);
	else if (!ft_strcmp(arr, "F"))
		return (F);
	else if (!ft_strcmp(arr, "C"))
		return (C);
	else
		return (-1);
}

static int	parse_color(t_map *map, char **splitted_line, int ele_type)
{
	char	**rgb;
	
	if (cnt_comma(splitted_line[1]) != 2)
		return (error_ret("Color format invalid.", EXIT_FAILURE));
	rgb = ft_split(splitted_line[1], ',');
	if (!rgb)
		return (error_ret("Error: split failed.", EXIT_FAILURE));
	if (ft_2d_len(rgb) != 3 
		|| splitted_line[1][ft_strlen(splitted_line[1] - 1) == ','])
	{
		ft_clean_2d(&rgb);
		return (error_ret("Color format invalid.", EXIT_FAILURE));
	}
	if ((ele_type == F
		&& (get_color(rgb, &map->f_color) == EXIT_FAILURE))
		|| (ele_type == C
		&& (get_color(rgb, &map->c_color) == EXIT_FAILURE)))
	{
		ft_clean_2d(&rgb);
		return (EXIT_FAILURE);
	}
	ft_clean_2d(&rgb);
	return (EXIT_SUCCESS);
}

static int	asign_ele(t_map *map, char **splitted_line, int ele_type)
{
	if (ele_type == F || ele_type == C)
		return (parse_color(map, splitted_line, ele_type));
	// continue with validate png
	return (0);
}

static int	parse_ele(t_map *map, char **splitted_line, int ele_type)
{
	if ((ele_type == NO && map->no)
		|| (ele_type == SO && map->so)
		|| (ele_type == WE && map->we)
		|| (ele_type == EA && map->ea)
		|| (ele_type == F && map->f_color)
		|| (ele_type == C && map->c_color))
		{
			ft_clean_2d(&splitted_line);
			return (error_ret("Error: Duplication Elements.", EXIT_FAILURE));
		}
		if (asign_ele(map, splitted_line, ele_type) == EXIT_FAILURE)
		{
			ft_clean_2d(&splitted_line);
			return (EXIT_FAILURE);
		}
	return (0);
}

int	read_ele(t_map *map, char *line)
{
	char	**splitted_line;
	int		size;
	int		ele_type;

	(void)map;
	if (!line[0])
		return (EXIT_SUCCESS);
	splitted_line = ft_split(line, ' ');
	printf("splited: %s\n", splitted_line[0]);
	if (!splitted_line)
		return (error_ret("Error: ft_split failed.", EXIT_FAILURE));
	size = ft_2d_len(splitted_line);
	if (size != 2)
	{
		ft_clean_2d(&splitted_line);
		return (error_ret("Element format: invalid.", EXIT_FAILURE));
	}
	ele_type = ele_type_check(splitted_line[0]);
	if (ele_type == -1)
	{
		ft_clean_2d(&splitted_line);
		return (error_ret("Element type: invalid.", EXIT_FAILURE));
	}
	return (parse_ele(map, splitted_line, ele_type));
}

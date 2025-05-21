/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ele.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:46:56 by tripham           #+#    #+#             */
/*   Updated: 2025/05/21 22:20:58 by tripham          ###   ########.fr       */
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
	printf("ele_type: %d\n", ele_type);
	if (ele_type == -1)
	{
		ft_clean_2d(&splitted_line);
		return (error_ret("Element type: invalid.", EXIT_FAILURE));
	}
	return (0);
}

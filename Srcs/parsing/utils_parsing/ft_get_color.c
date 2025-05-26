/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:43:53 by tripham           #+#    #+#             */
/*   Updated: 2025/05/22 23:10:10 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_sigle_color(const char *color)
{
	int	color_val;

	if (!color[0] || ft_strlen(color) > 3)
		return (-1);
	color_val = 0;
	while (*color)
	{
		if (*color < '0' || *color > '9')
			return (-1);
		color_val = color_val * 10 + *color++ - '0';
	}
	if (color_val > 255)
		return (-1);
	return (color_val);
}

int	get_color(char **rgb, int *c_or_f)
{
	int	r;
	int	g;
	int	b;

	r = get_sigle_color(rgb[0]);
	g = get_sigle_color(rgb[1]);
	b = get_sigle_color(rgb[2]);
	if (r == -1 || g == -1 || b == -1)
		return (error_ret("Color format invalid.", EXIT_FAILURE));
	*c_or_f = (r << 24) + (g << 16) + (b << 8) + 255;
	return (EXIT_SUCCESS);
}

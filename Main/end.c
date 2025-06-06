/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:32:41 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/06 20:26:46 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_ends(t_cub* c, char *str, int exitcode)
{
	if (!c)
		return
	clean_assets(c, &c->assets);
	clean_map(&c->map);
	if (exitcode)
		ft_printf_fd(2, "%s\n", str);
	exit(exitcode);
}

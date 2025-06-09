/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:03:54 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 09:56:43 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handler_close(void *data)
{
	t_cub	*c;

	c = (t_cub *)data;
	cub3d_ends(c, "Done", EXIT_SUCCESS);
}

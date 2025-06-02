/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:35:22 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/03 02:04:31 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H

 #define HANDLER_H

#include "cub3d.h"

typedef struct s_cub	t_cub;
typedef struct s_assets t_assets;

void	handler_loop(void* data);
void	handler_close(void* data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:30:06 by caonguye          #+#    #+#             */
/*   Updated: 2025/06/09 09:47:57 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H

# include "cub3d.h"

typedef struct s_cub	t_cub;
typedef struct s_assets	t_assets;

void	exec_clean(t_cub *c);
void	clean_assets(t_cub *c, t_assets *as);

#endif
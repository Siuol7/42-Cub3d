/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:41:09 by tripham           #+#    #+#             */
/*   Updated: 2025/05/22 22:53:51 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# ifndef G_BUFFER
#  define G_BUFFER 1000
# endif 

# include "MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "fcntl.h"
# include "cub3d.h"

typedef struct s_cub	t_cub;

typedef struct s_point
{
	int	row;
	int	col;
}	t_point;

/*	t_dpoint
*	Real point (maps coordinates in double type)
*/
typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

/*	t_color
*	RGBA color is packed into uint32_t
*/
typedef struct s_color
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;
}	t_color;

int		map_validation(char *path);

// parsing utils

char	*ft_readline(int fd, int *eof);
int		ft_is_all_white_spaces(char *s);
int		ft_2d_len(char **arr);
void	ft_clean_2d(char ***arr);
int		cnt_comma(char *str);
int		get_color(char **rgb, int *c_or_f);

// ERROR
int		multi_err_ret(char *str1, char *str2, int num);
char	*error_ret_null(char *str);
int		multi_err_ret(char *str1, char *str2, int num);
int		error_ret(char *str, int return_code);
void	ft_error(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:29:08 by tripham           #+#    #+#             */
/*   Updated: 2025/06/07 23:46:19 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*error_ret_null(char *str)
{
	ft_error(str);
	return (NULL);
}

int	multi_err_ret(char *str1, char *str2, int num)
{
	ft_printf_fd(2, "\n[Error]\n%s: %s\n\n", str1, str2);
	return (num);
}

void	ft_error(char *str)
{
	if (mlx_errno)
		ft_printf_fd(2, "[Error MLX]\n%s: %s\n\n", str,
			mlx_strerror(mlx_errno));
	else if (errno)
		ft_printf_fd(2, "[Error System]\n%s: %s\n\n", str, strerror(errno));
	else
		ft_printf_fd(2, "[Error]\n%s\n", str);
}

int	error_ret(char *str, int return_code)
{
	ft_error(str);
	return (return_code);
}

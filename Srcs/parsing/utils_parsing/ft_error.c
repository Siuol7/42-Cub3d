/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:29:08 by tripham           #+#    #+#             */
/*   Updated: 2025/05/18 21:00:00 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_multi_err_ret(char *str1, char *str2, int num)
{
	ft_printf_fd(2, "\n[Error]\n%s: %s\n\n", str1, str2);
	return (num);
}

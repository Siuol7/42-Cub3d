/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:42:33 by tripham           #+#    #+#             */
/*   Updated: 2025/05/21 23:00:56 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(char *buffer, char c);

char	*get_next_line(int fd);
char	*ft_strncpy_gnl(char *dest, char *src, unsigned int len);
char	*ft_substring(char *main_buffer, int start, int end);
char	*ft_buffer_join(char *main_buffer, char *sub_buffer);
char	*ft_free(char **buffer);

#endif

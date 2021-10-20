/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:20:17 by mteerlin      #+#    #+#                 */
/*   Updated: 2021/10/17 13:54:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include "../cub3d.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(char **line, int fd);
char	*gnl_strchr(const char *s, int c);
void	gnl_strncpy(char *dst, const char *src, size_t n);
void	gnl_strncat(char *dst, char *src, size_t n);
char	*gnl_strdup(const char *s);
char	*gnl_strjoin(char *d, char *s);

#endif

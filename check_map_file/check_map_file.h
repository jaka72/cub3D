/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_file.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:54:21 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_FILE_H
# define CHECK_MAP_FILE_H

# include "../cub3d.h"

int		check_map_file(char *file, t_window *w);
int		check_first_char(char *line, t_window *w);
int		check_other_chars(char *line, t_window *w);
void	check_if_rgb_or_path(char *line, int i, char c, t_window *w);
int		count_positioners_and_sprites(char *line, t_window *w);
int		open_file_and_reset_flags(t_window *w, char *file, int *fd,
			int *ret_gnl);
int		check_identifiers_and_close_file(int fd, t_window *w);

#endif
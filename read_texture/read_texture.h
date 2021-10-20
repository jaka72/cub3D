/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_texture.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:53:42 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_TEXTURE_H
# define READ_TEXTURE_H

# include "../cub3d.h"

int		get_texture(t_window *window, char *path, t_texx *tex);
int		read_all_textures(t_window *window);

#endif

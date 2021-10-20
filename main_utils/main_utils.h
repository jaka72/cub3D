/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:16:06 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include "../cub3d.h"

void	init_keys(t_window *window);
void	choose_keys(t_window *window);

//void	choose_keys(void);
int		key_press(int key, t_window *window);
int		key_release(int key, t_window *window);

// THIS IS IN TWO DIFFERENT FILES, 1 FOR EACH OS, DECIDED AT MAKEFILE
int		check_screen_resol(t_window *window);
void	my_pixel_put(t_window *window, float x, float y, int color);

void	my_pixel_put_front(t_window *window, int x, int y, int color);

#endif

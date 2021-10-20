/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:11:35 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../cub3d.h"

void	topdown_view(int top, t_window *window);
void	print_sky_xpm(t_window *window);
void	draw_grid(t_window *window);
int		draw_map(t_window *window);
int		ray_n(t_window *window, float angle);
int		ray_e(t_window *window, float angle);
int		ray_s(t_window *window, float angle);
int		ray_w(t_window *window, float angle);
void	draw_hands(t_window *window, int rotation);
int		wall_color(t_window *w);

#endif

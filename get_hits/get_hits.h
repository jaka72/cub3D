/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hits.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:54:15 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_HITS_H
# define GET_HITS_H

# include "../cub3d.h"

void	q1_hor_hit(t_window *w, float angle_i);
void	q1_ver_hit(t_window *w, float angle_i);
void	q2_hor_hit(t_window *w, float angle_i);
void	q2_ver_hit(t_window *w, float angle_i);
void	q3_hor_hit(t_window *w, float angle_i);
void	q3_ver_hit(t_window *w, float angle_i);
void	q4_hor_hit(t_window *w, float angle_i);
void	q4_ver_hit(t_window *w, float angle_i);

#endif

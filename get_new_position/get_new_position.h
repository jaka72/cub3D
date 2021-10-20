/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_new_position.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:54:15 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEW_POSITION_H
# define GET_NEW_POSITION_H

# include "../cub3d.h"

void	new_position_w_q1(float old_posX, float old_posY, t_window *w);
void	new_position_w_q2(float old_posX, float old_posY, t_window *w);
void	new_position_w_q3(float old_posX, float old_posY, t_window *w);
void	new_position_w_q4(float old_posX, float old_posY, t_window *w);
void	new_position_s_q1(float old_posX, float old_posY, t_window *w);
void	new_position_s_q2(float old_posX, float old_posY, t_window *w);
void	new_position_s_q3(float old_posX, float old_posY, t_window *w);
void	new_position_s_q4(float old_posX, float old_posY, t_window *w);
void	new_position_a_q1(float old_posX, float old_posY, t_window *w);
void	new_position_a_q2(float old_posX, float old_posY, t_window *w);
void	new_position_a_q3(float old_posX, float old_posY, t_window *w);
void	new_position_a_q4(float old_posX, float old_posY, t_window *w);
void	new_position_d_q1(float old_posX, float old_posY, t_window *w);
void	new_position_d_q2(float old_posX, float old_posY, t_window *w);
void	new_position_d_q3(float old_posX, float old_posY, t_window *w);
void	new_position_d_q4(float old_posX, float old_posY, t_window *w);

#endif
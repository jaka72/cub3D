/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 11:32:55 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:53:46 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_rotation(t_window *w)
{
	if (w->key[ROT_RIGHT] == TRUE)
	{
		w->pos.myrot += 2;
		if (w->pos.myrot >= 360)
			w->pos.myrot = 0;
	}
	else if (w->key[ROT_LEFT] == TRUE)
	{
		w->pos.myrot -= 2;
		if (w->pos.myrot < 0)
			w->pos.myrot = 359;
	}
}

void	render_left_right(t_window *w, float old_posx, float old_posy)
{
	if (w->key[LEFT] == TRUE)
	{
		if (w->pos.myrot >= 0 && w->pos.myrot < 90)
			new_position_a_q1(old_posx, old_posy, w);
		else if (w->pos.myrot >= 90 && w->pos.myrot < 180)
			new_position_a_q2(old_posx, old_posy, w);
		else if (w->pos.myrot >= 180 && w->pos.myrot < 270)
			new_position_a_q3(old_posx, old_posy, w);
		else if (w->pos.myrot >= 270 && w->pos.myrot < 360)
			new_position_a_q4(old_posx, old_posy, w);
	}
	else if (w->key[RIGHT] == TRUE)
	{
		if (w->pos.myrot >= 0 && w->pos.myrot < 90)
			new_position_d_q1(old_posx, old_posy, w);
		else if (w->pos.myrot >= 90 && w->pos.myrot < 180)
			new_position_d_q2(old_posx, old_posy, w);
		else if (w->pos.myrot >= 180 && w->pos.myrot < 270)
			new_position_d_q3(old_posx, old_posy, w);
		else if (w->pos.myrot >= 270 && w->pos.myrot < 360)
			new_position_d_q4(old_posx, old_posy, w);
	}
}

void	render_forw_backw(t_window *w, float old_posx, float old_posy)
{
	if (w->key[FORW] == TRUE)
	{
		if (w->pos.myrot >= 0 && w->pos.myrot < 90)
			new_position_w_q1(old_posx, old_posy, w);
		else if (w->pos.myrot >= 90 && w->pos.myrot < 180)
			new_position_w_q2(old_posx, old_posy, w);
		else if (w->pos.myrot >= 180 && w->pos.myrot < 270)
			new_position_w_q3(old_posx, old_posy, w);
		else if (w->pos.myrot >= 270 && w->pos.myrot < 360)
			new_position_w_q4(old_posx, old_posy, w);
	}
	else if (w->key[BACKW] == TRUE)
	{
		if (w->pos.myrot >= 0 && w->pos.myrot < 90)
			new_position_s_q1(old_posx, old_posy, w);
		else if (w->pos.myrot >= 90 && w->pos.myrot < 180)
			new_position_s_q2(old_posx, old_posy, w);
		else if (w->pos.myrot >= 180 && w->pos.myrot < 270)
			new_position_s_q3(old_posx, old_posy, w);
		else if (w->pos.myrot >= 270 && w->pos.myrot < 360)
			new_position_s_q4(old_posx, old_posy, w);
	}
}

int	render(t_window *window)
{
	float	old_posx;
	float	old_posy;

	old_posx = window->pos.my_x;
	old_posy = window->pos.my_y;
	if (window->key[FORW] == TRUE || window->key[BACKW] == TRUE)
		render_forw_backw(window, old_posx, old_posy);
	else if (window->key[LEFT] == TRUE || window->key[RIGHT] == TRUE)
		render_left_right(window, old_posx, old_posy);
	else if (window->key[ROT_RIGHT] == TRUE || window->key[ROT_LEFT] == TRUE)
		render_rotation(window);
	draw_fov(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img02, 0, 0);
	return (0);
}

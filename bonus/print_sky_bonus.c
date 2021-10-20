/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_sky_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 11:26:16 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:01:57 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

// Used in print_sky_xpm
// HERE IT IS REVERSED, COLS ARE ROWS, ROWS ARE COLS
void	calculate_pixel_position(t_window *window, float *rot,
	int *x, float step_k)
{	
	int		y;
	float	newstep;
	float	k;

	y = 0;
	newstep = 0;
	if (*rot > window->tex.sky.rows)
	{
		newstep = 0;
		*rot = 0;
	}
	while (y < window->height / 2)
	{	
		k = floor((int)newstep) * (window->tex.sky.rows);
		if (k > window->tex.sky.cols * (window->tex.sky.rows))
			break ;
		my_pixel_put_front(window, *x, y, window->tex.sky.map[(int)(k + *rot)]);
		newstep = newstep + step_k;
		y++;
	}
	*x = *x + 1;
	*rot = *rot + 1;
}

// HERE IT IS REVERSED, COLS ARE ROWS, ROWS ARE COLS
void	print_sky_xpm(t_window *window)
{
	int		x;
	float	step_k;
	float	rot;

	x = 0;
	step_k = (float)window->tex.sky.cols / ((float)window->height
			/ 2);
	rot = (float)window->tex.sky.rows / 360 * window->pos.myrot;
	while (x < window->width)
		calculate_pixel_position(window, &rot, &x, step_k);
}

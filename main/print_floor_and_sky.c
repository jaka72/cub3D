/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_floor_and_sky.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 11:26:16 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:14:43 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_sky(t_window *window)
{
	int	x;
	int	y;
	int	divide_window;

	divide_window = 2;
	y = 0;
	while (y < window->height / divide_window)
	{
		x = 0;
		while (x < window->width)
		{
			my_pixel_put_front(window, x, y, window->data.sky_color);
			x++;
		}
		y++;
	}
}

void	print_floor(t_window *window)
{
	int	x;
	int	y;

	y = window->height / 2;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			my_pixel_put_front(window, x, y, window->data.floor_color);
			x++;
		}
		y++;
	}
}

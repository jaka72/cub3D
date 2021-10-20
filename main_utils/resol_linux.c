/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resol_linux.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 19:31:39 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/27 18:25:32 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_utils.h"

int	check_screen_resol(t_window *window)
{
	Display	*disp;
	Screen	*scrn;	

	disp = XOpenDisplay(NULL);
	scrn = DefaultScreenOfDisplay(disp);
	window->data.screen_height = scrn->height;
	window->data.screen_width = scrn->width;
	XCloseDisplay(disp);
	if (window->data.resol_width > window->data.screen_width)
		window->data.resol_width = window->data.screen_width;
	if (window->data.resol_height > window->data.screen_height)
		window->data.resol_height = window->data.screen_height;
	if (window->value.resol == 0)
	{
		window->data.resol_width = window->data.screen_width / 3;
		window->data.resol_height = window->data.screen_height / 2;
	}
	window->width = window->data.resol_width;
	window->height = window->data.resol_height;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resol_mac.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 19:31:44 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/27 18:27:17 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main_utils.h"

int	check_screen_resol(t_window *window)
{
	int auto mainDisplayId = CGMainDisplayID();
	window->data.screen_width = CGDisplayPixelsWide(mainDisplayId);
	window->data.screen_height = CGDisplayPixelsHigh(mainDisplayId);
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

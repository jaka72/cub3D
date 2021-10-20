/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hits_minimap.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 18:56:33 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/16 11:26:18 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	wall_color(t_window *w)
{
	if (w->map.field_size <= 2)
		return (0x00c0c0c0);
	return (0x00303030);
}

void	print_hits(t_window *w)
{
	if (w->dist.hor < w->dist.ver)
		my_pixel_put(w, w->hit.xh, w->hit.yh, 0x000ff00);
	else
		my_pixel_put(w, w->hit.xv, w->hit.yv, 0x0000ff00);
}

void	draw_fov_hits(t_window *w)
{
	float	angle;
	float	angle_i;

	set_quadrant_and_angle(w, &angle_i);
	w->hit.slice_x = 0;
	angle = -30;
	while (w->hit.slice_x < w->data.resol_width)
	{
		get_hits(w, angle_i);
		print_hits(w);
		angle_i = angle_i + w->pos.fov_step;
		angle = angle + w->pos.fov_step;
		w->hit.slice_x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_rays_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 15:19:53 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:57:30 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ray_n(t_window *w, float angle)
{
	float	op;
	int		adj;
	int		field_nr;
	int		x;
	int		y;

	x = w->pos.my_x * w->map.field_size;
	y = w->pos.my_y * w->map.field_size;
	adj = 1.0;
	while (adj)
	{
		op = tan(angle * RAD) * adj;
		field_nr = (int)((x + op) / w->map.field_size) + \
			((int)(y / w->map.field_size)) * w->map.nr_cols;
		if (w->map.plan[field_nr] == '1')
			break ;
		my_pixel_put_front(w, x + op, y, 0x0000ff00);
		y--;
		adj++;
	}
	return (0);
}

int	ray_e(t_window *w, float angle)
{
	float	op;
	int		adj;
	int		field_nr;
	int		x;
	int		y;

	angle = angle + 270;
	x = w->pos.my_x * w->map.field_size;
	y = w->pos.my_y * w->map.field_size;
	adj = 1.0;
	while (1)
	{
		op = tan(angle * RAD) * adj;
		field_nr = (int)(x / w->map.field_size) + \
			((int)(y + op) / w->map.field_size) * w->map.nr_cols;
		if (w->map.plan[field_nr] == '1')
			break ;
		my_pixel_put_front(w, x, y + op, 0x0000ff00);
		x++;
		adj++;
	}
	return (0);
}

int	ray_s(t_window *w, float angle)
{
	float	op;
	int		adj;
	int		field_nr;
	int		x;
	int		y;

	angle = angle + 180;
	x = w->pos.my_x * w->map.field_size;
	y = w->pos.my_y * w->map.field_size;
	adj = 1.0;
	while (1)
	{
		op = tan(angle * RAD) * adj;
		field_nr = (int)((x - op) / w->map.field_size) + \
			((int)(y / w->map.field_size)) * w->map.nr_cols;
		if (w->map.plan[field_nr] == '1')
			break ;
		my_pixel_put_front(w, x - op, y, 0x0000ff00);
		y++;
		adj++;
	}
	return (0);
}

int	ray_w(t_window *w, float angle)
{
	float	op;
	int		adj;
	int		field_nr;
	int		x;
	int		y;

	angle = angle + 90;
	x = w->pos.my_x * w->map.field_size;
	y = w->pos.my_y * w->map.field_size;
	adj = 1.0;
	while (1)
	{
		op = tan(angle * RAD) * adj;
		field_nr = (int)(x / w->map.field_size) + \
			((int)(y - op) / w->map.field_size) * w->map.nr_cols;
		if (w->map.plan[field_nr] == '1')
			break ;
		my_pixel_put_front(w, x, y - op, 0x0000ff00);
		x--;
		adj++;
	}
	return (0);
}

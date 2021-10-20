/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_grid_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 19:31:53 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:11:47 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

// field_size for minimap
void	get_field_size(t_window *w)
{
	w->map.field_size = ceil(w->data.resol_width / 3 / w->map.nr_cols);
	if (w->map.nr_rows >= w->map.nr_cols)
		w->map.field_size = ceil(w->data.resol_height / 3 / w->map.nr_rows);
	if ((w->map.field_size * w->map.nr_cols) < (w->data.resol_width * 0.49)
		&& (w->map.field_size * w->map.nr_rows) < (w->data.resol_height * 0.49))
		w->map.field_size++;
	if (w->map.field_size == 1)
		w->map.field_size = 2;
	if ((w->map.field_size * 2 * w->map.nr_cols) > w->data.resol_width
		|| (w->map.field_size * 2 * w->map.nr_rows) > w->data.resol_height)
		w->map.field_size = 0;
}

void	draw_grid(t_window *w)
{
	int	i;
	int	j;

	j = w->map.field_size - 1;
	while (j < w->map.nr_rows * w->map.field_size)
	{
		i = 0;
		while (i < w->map.nr_cols * w->map.field_size)
		{
			my_pixel_put_front(w, i, j, 0x00101010);
			i++;
		}
		j += w->map.field_size;
	}
	j = w->map.field_size - 1;
	while (j < w->map.nr_cols * w->map.field_size)
	{
		i = 0;
		while (i < w->map.nr_rows * w->map.field_size)
		{
			my_pixel_put_front(w, j, i, 0x00101010);
			i++;
		}
		j += w->map.field_size;
	}
}

int	draw_field(t_window *w, int pos, int cols, int color)
{
	int	i;
	int	j;
	int	posx;
	int	posy;

	posx = (pos % cols) * w->map.field_size;
	posy = (pos / cols) * w->map.field_size;
	j = 0;
	while (j < w->map.field_size)
	{
		i = 0;
		while (i < w->map.field_size)
		{
			my_pixel_put_front(w, posx + i, posy + j, color);
			i++;
		}
		j++;
	}
	return (0);
}

int	draw_map(t_window *w)
{
	int	pos;

	pos = 0;
	while (pos < w->map.nr_fields)
	{
		if (w->map.plan[pos] == '1')
			draw_field(w, pos, w->map.nr_cols, wall_color(w));
		else if (w->map.plan[pos] == '0' || w->map.plan[pos] == 'N'
			|| w->map.plan[pos] == 'E' || w->map.plan[pos] == 'S'
			|| w->map.plan[pos] == 'W')
			draw_field(w, pos, w->map.nr_cols, 0x00000000);
		else if (w->map.plan[pos] == '*')
			draw_field(w, pos, w->map.nr_cols, 0x00505050);
		else if (w->map.plan[pos] == ' ')
			draw_field(w, pos, w->map.nr_cols, 0x00404040);
		else if (w->map.plan[pos] == '2' || w->map.plan[pos] == '3'
			|| w->map.plan[pos] == '4')
			draw_field(w, pos, w->map.nr_cols, 0x0000c100);
		pos++;
	}
	return (0);
}

void	draw_hands(t_window *window, int rotation)
{
	if ((rotation >= 315 && rotation < 360)
		|| (rotation >= 0 && rotation < 45))
		ray_n(window, rotation);
	else if (rotation >= 45 && rotation < 135)
		ray_e(window, rotation);
	else if (rotation >= 135 && rotation < 225)
		ray_s(window, rotation);
	else if (rotation >= 225 && rotation < 315)
		ray_w(window, rotation);
}

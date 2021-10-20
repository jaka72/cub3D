/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quad_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 19:15:34 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 12:53:14 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_hits.h"

int	q3_check_first_field_hor(t_window *w, float angle_i)
{
	if (angle_i >= 90)
	{
		q4_hor_hit(w, angle_i - 90);
		return (0);
	}
	w->pos.current_quad = 3;
	w->hit.adj = ceil(w->pos.my_y) - w->pos.my_y;
	w->hit.op = w->hit.adj * tan(angle_i * RAD);
	w->hit.x = w->pos.my_x - w->hit.op;
	w->hit.y = ceil(w->pos.my_y);
	if (w->hit.y > w->map.nr_rows || w->hit.y < 1 || w->hit.x < 1
		|| isnan(w->hit.x))
	{
		distance_hor(w, w->hit.op, angle_i);
		return (0);
	}
	w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols;
	if (w->map.plan[w->hit.field] == '1')
	{
		distance_hor(w, w->hit.op, angle_i);
		return (0);
	}
	return (1);
}

void	q3_hor_hit(t_window *w, float angle_i)
{
	if (q3_check_first_field_hor(w, angle_i) == 0)
		return ;
	while (w->hit.y < w->map.nr_rows)
	{
		w->hit.adj = w->hit.adj + 1;
		w->hit.op = w->hit.adj * tan(angle_i * RAD);
		w->hit.x = w->pos.my_x - w->hit.op;
		w->hit.y = w->hit.y + 1;
		if (w->hit.x < 1)
			break ;
		if (w->hit.y > w->map.nr_rows || w->hit.y < 1
			|| w->hit.x < 1 || isnan(w->hit.x))
		{
			distance_hor(w, w->hit.op, angle_i);
			return ;
		}
		w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols;
		if (w->map.plan[w->hit.field] == '1')
		{
			distance_hor(w, w->hit.op, angle_i);
			return ;
		}
	}
	distance_hor(w, w->hit.op, angle_i);
}

int	q3_check_first_field_ver(t_window *w, float angle_i)
{
	if (angle_i >= 90)
	{
		q4_ver_hit(w, angle_i - 90);
		return (0);
	}
	w->pos.current_quad = 3;
	w->hit.op = w->pos.my_x - floor(w->pos.my_x);
	w->hit.adj = w->hit.op / tan(angle_i * RAD);
	w->hit.x = floor(w->pos.my_x);
	w->hit.y = w->pos.my_y + w->hit.adj;
	if (w->hit.y > w->map.nr_rows || w->hit.y < 1 || w->hit.x < 1
		|| isnan(w->hit.y) || isinf(w->hit.y))
	{
		distance_ver(w, w->hit.op, angle_i);
		return (0);
	}
	w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols - 1;
	if (w->map.plan[w->hit.field] == '1')
	{
		distance_ver(w, w->hit.op, angle_i);
		return (0);
	}
	return (1);
}

void	q3_ver_hit(t_window *w, float angle_i)
{
	if (q3_check_first_field_ver(w, angle_i) == 0)
		return ;
	while (w->hit.y < w->map.nr_rows)
	{
		w->hit.op = w->hit.op + 1;
		w->hit.adj = w->hit.op / tan(angle_i * RAD);
		w->hit.x = w->hit.x - 1;
		w->hit.y = w->pos.my_y + w->hit.adj;
		if (w->hit.x < 1)
			break ;
		if (w->hit.y > w->map.nr_rows || w->hit.y < 1 || w->hit.x < 1
			|| isnan(w->hit.y) || isinf(w->hit.y))
		{
			distance_ver(w, w->hit.op, angle_i);
			return ;
		}
		w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols - 1;
		if (w->map.plan[w->hit.field] == '1')
		{
			distance_ver(w, w->hit.op, angle_i);
			return ;
		}
	}
	distance_ver(w, w->hit.op, angle_i);
}

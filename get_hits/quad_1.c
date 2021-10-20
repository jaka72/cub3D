/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quad_1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 15:37:53 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 12:52:57 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_hits.h"

int	q1_check_first_field_hor(t_window *w, float angle_i)
{
	if (angle_i >= 90)
	{
		q2_hor_hit(w, angle_i - 90);
		return (0);
	}
	w->pos.current_quad = 1;
	w->hit.adj = w->pos.my_y - floor(w->pos.my_y);
	w->hit.op = w->hit.adj * tan(angle_i * RAD);
	w->hit.x = w->pos.my_x + w->hit.op;
	w->hit.y = floor(w->pos.my_y);
	if (w->hit.x > w->map.nr_cols || w->hit.y < 1
		|| w->hit.y > w->map.nr_rows - 1 || isnan(w->hit.y))
	{
		distance_hor(w, w->hit.op, angle_i);
		return (0);
	}
	w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols
		- w->map.nr_cols;
	if (w->map.plan[w->hit.field] == '1')
	{
		distance_hor(w, w->hit.op, angle_i);
		return (0);
	}
	return (1);
}

void	q1_hor_hit(t_window *w, float angle_i)
{
	if (q1_check_first_field_hor(w, angle_i) == 0)
		return ;
	while (w->hit.y > 1)
	{
		w->hit.adj = w->hit.adj + 1;
		w->hit.op = w->hit.adj * tan(angle_i * RAD);
		w->hit.x = w->pos.my_x + w->hit.op;
		w->hit.y = w->hit.y - 1;
		if (w->hit.x > w->map.nr_cols)
			break ;
		if (w->hit.x > w->map.nr_cols || w->hit.y < 1
			|| w->hit.y > w->map.nr_rows - 1)
		{
			distance_hor(w, w->hit.op, angle_i);
			return ;
		}
		w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols
			- w->map.nr_cols;
		if (w->map.plan[w->hit.field] == '1')
		{
			distance_hor(w, w->hit.op, angle_i);
			return ;
		}
	}
	distance_hor(w, w->hit.op, angle_i);
}

int	q1_check_first_field_ver(t_window *w, float angle_i)
{
	if (angle_i >= 90)
	{
		q2_ver_hit(w, angle_i - 90);
		return (0);
	}
	w->pos.current_quad = 1;
	w->hit.op = ceil(w->pos.my_x) - w->pos.my_x;
	w->hit.adj = w->hit.op / tan(angle_i * RAD);
	w->hit.x = ceil(w->pos.my_x);
	w->hit.y = w->pos.my_y - w->hit.adj;
	if (w->hit.x > w->map.nr_cols || w->hit.y < 1
		|| w->hit.y > w->map.nr_rows - 1 || isnan(w->hit.y))
	{
		distance_ver(w, w->hit.op, angle_i);
		return (0);
	}
	w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols;
	if (w->map.plan[w->hit.field] == '1')
	{
		distance_ver(w, w->hit.op, angle_i);
		return (0);
	}
	return (1);
}

void	q1_ver_hit(t_window *w, float angle_i)
{
	if (q1_check_first_field_ver(w, angle_i) == 0)
		return ;
	while (w->hit.y > 1)
	{
		w->hit.op = w->hit.op + 1;
		w->hit.adj = w->hit.op / tan(angle_i * RAD);
		w->hit.x = w->hit.x + 1;
		w->hit.y = w->pos.my_y - w->hit.adj;
		if (w->hit.x > w->map.nr_cols)
			break ;
		w->hit.field = floor(w->hit.x) + floor(w->hit.y) * w->map.nr_cols;
		if (w->hit.x > w->map.nr_cols || w->hit.y < 1
			|| w->hit.y > w->map.nr_rows - 1)
		{
			distance_ver(w, w->hit.op, angle_i);
			return ;
		}
		if (w->map.plan[w->hit.field] == '1')
		{
			distance_ver(w, w->hit.op, angle_i);
			return ;
		}
	}
	distance_ver(w, w->hit.op, angle_i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_dist_and_height.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 11:50:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:13:29 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_hits(t_window *w, float angle_i)
{
	if (w->pos.start_quad == 1)
	{
		q1_hor_hit(w, angle_i);
		q1_ver_hit(w, angle_i);
	}
	else if (w->pos.start_quad == 2)
	{
		q2_hor_hit(w, angle_i);
		q2_ver_hit(w, angle_i);
	}
	else if (w->pos.start_quad == 3)
	{
		q3_hor_hit(w, angle_i);
		q3_ver_hit(w, angle_i);
	}
	else if (w->pos.start_quad == 4)
	{
		q4_hor_hit(w, angle_i);
		q4_ver_hit(w, angle_i);
	}
}

// distance * w->hit.dpp  :Correction to get perfect square
void	calc_wall_height(float distance, float angle, t_texx *t_tex,
						t_window *w)
{
	distance = distance * cos(angle * RAD);
	w->hit.wall_height = (float)w->map.field_width / distance * w->hit.dpp;
	if (w->hit.wall_side == HOR)
		t_tex->x = t_tex->rows * (w->hit.xh - floor(w->hit.xh));
	else if (w->hit.wall_side == VER)
		t_tex->x = t_tex->rows * (w->hit.yv - floor(w->hit.yv));
}

// cols * 100  :PROTECTION, WHEN RAY POINTS EXACTLY PARALEL TO X GRID
// PROTECTION WHEN ANGLE == 0, THEN op IS ZERO, WHICH MUST NOT HAPPEN
void	distance_hor(t_window *w, float op, float angle_i)
{
	if (w->hit.x < 1 || w->hit.x > w->map.nr_cols || !isnormal(w->hit.x)
		|| w->hit.y < 1)
	{
		w->dist.hor = w->map.nr_cols * 100;
		return ;
	}
	w->dist.hor = op / sin(angle_i * RAD);
	if (op == 0)
		w->dist.hor = w->hit.y - w->pos.my_y;
	if (w->dist.hor < 0)
		w->dist.hor = w->dist.hor * -1;
	w->hit.xh = w->hit.x;
	w->hit.yh = w->hit.y;
}

// cols * 100  :PROTECTION, WHEN RAY POINTS EXACTLY PARALEL TO X GRID
// PROTECTION WHEN ANGLE == 0, THEN op IS ZERO, WHICH MUST NOT HAPPEN
void	distance_ver(t_window *w, float op, float angle_i)
{
	if (w->hit.y < 1 || w->hit.y > w->map.nr_rows || !isnormal(w->hit.y))
	{
		w->dist.ver = w->map.nr_cols * 100;
		return ;
	}
	w->dist.ver = op / sin(angle_i * RAD);
	if (op == 0)
		w->dist.ver = w->hit.x - w->pos.my_x;
	if (w->dist.ver < 0)
		w->dist.ver = w->dist.ver * -1;
	w->hit.xv = w->hit.x;
	w->hit.yv = w->hit.y;
}

// QUAD1 UPPER-RIGHT, QUAD2 LOWER-RIGHT, QUAD3 LOWER-LEFT ...
// pos.angle is for moving with keys w,s,a,d
void	set_quadrant_and_angle(t_window *w, float *angle_i)
{
	if (w->pos.myrot >= 30 && w->pos.myrot < 120)
	{
		w->pos.start_quad = 1;
		*angle_i = w->pos.myrot - 30;
	}												
	else if (w->pos.myrot >= 120 && w->pos.myrot < 210)
	{
		w->pos.start_quad = 2;
		*angle_i = w->pos.myrot - 120;
	}
	else if (w->pos.myrot >= 210 && w->pos.myrot < 300)
	{
		w->pos.start_quad = 3;
		*angle_i = w->pos.myrot - 210;
	}
	else if ((w->pos.myrot >= 300 && w->pos.myrot < 360)
		|| (w->pos.myrot >= 0 && w->pos.myrot < 30))
	{
		w->pos.start_quad = 4;
		*angle_i = w->pos.myrot - 300;
		if (w->pos.myrot >= 0 && w->pos.myrot < 30)
			*angle_i = w->pos.myrot + 60;
	}
}

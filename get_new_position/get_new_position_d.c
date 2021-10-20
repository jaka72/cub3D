/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_new_position_d.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 11:49:41 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:57:30 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_new_position.h"

void	new_position_d_q1(float old_posX, float old_posY, t_window *w)
{
	int	fieldnr;

	fieldnr = (int)(floor(old_posX) + floor(old_posY) * w->map.nr_cols);
	w->pos.my_x = w->pos.my_x + sin((90 - w->pos.myrot) * RAD) * STEP;
	w->pos.my_y = w->pos.my_y + cos((90 - w->pos.myrot) * RAD) * STEP;
	if (w->pos.my_x - floor(w->pos.my_x) > NEAR_CEIL)
		if (w->map.plan[fieldnr + 1] == '1')
			w->pos.my_x = ceil(old_posX) - NEAR_FLOOR;
	if (w->pos.my_y - floor(w->pos.my_y) > NEAR_CEIL)
		if (w->map.plan[fieldnr + w->map.nr_cols] == '1')
			w->pos.my_y = ceil(old_posY) - NEAR_FLOOR;
	if (floor(old_posX) != floor(w->pos.my_x))
		if (w->map.plan[fieldnr + 1] == '1')
			w->pos.my_x = old_posX;
	if (floor(old_posY) != floor(w->pos.my_y))
		if (w->map.plan[fieldnr + w->map.nr_cols] == '1')
			w->pos.my_y = old_posY;
	if (w->pos.my_x - floor(w->pos.my_x) > NEAR_CEIL
		&& w->pos.my_y - floor(w->pos.my_y) > NEAR_CEIL
		&& w->map.plan[fieldnr + 1] != '1'
		&& w->map.plan[fieldnr + w->map.nr_cols] != '1'
		&& w->map.plan[fieldnr + w->map.nr_cols + 1] == '1')
		w->pos.my_y = ceil(w->pos.my_y) - NEAR_FLOOR;
}

void	new_position_d_q2(float old_posX, float old_posY, t_window *w)
{
	int	fieldnr;

	fieldnr = (int)(floor(old_posX) + floor(old_posY) * w->map.nr_cols);
	w->pos.my_x = w->pos.my_x + sin((90 - w->pos.myrot) * RAD) * STEP;
	w->pos.my_y = w->pos.my_y + cos((90 - w->pos.myrot) * RAD) * STEP;
	if (w->pos.my_x - floor(w->pos.my_x) < NEAR_FLOOR)
		if (w->map.plan[fieldnr - 1] == '1')
			w->pos.my_x = floor(old_posX) + NEAR_FLOOR;
	if (w->pos.my_y - floor(w->pos.my_y) > NEAR_CEIL)
		if (w->map.plan[fieldnr + w->map.nr_cols] == '1')
			w->pos.my_y = ceil(old_posY) - NEAR_FLOOR;
	if (floor(old_posX) != floor(w->pos.my_x))
		if (w->map.plan[fieldnr - 1] == '1')
			w->pos.my_x = old_posX;
	if (floor(old_posY) != floor(w->pos.my_y))
		if (w->map.plan[fieldnr + w->map.nr_cols] == '1')
			w->pos.my_y = old_posY;
	if (w->pos.my_x - floor(w->pos.my_x) < NEAR_FLOOR
		&& w->pos.my_y - floor(w->pos.my_y) > NEAR_CEIL
		&& w->map.plan[fieldnr - 1] != '1'
		&& w->map.plan[fieldnr + w->map.nr_cols] != '1'
		&& w->map.plan[fieldnr + w->map.nr_cols - 1] == '1')
		w->pos.my_y = ceil(w->pos.my_y) - NEAR_FLOOR;
}

void	new_position_d_q3(float old_posX, float old_posY, t_window *w)
{
	int	fieldnr;

	fieldnr = (int)(floor(old_posX) + floor(old_posY) * w->map.nr_cols);
	w->pos.my_x = w->pos.my_x - sin((90 - (w->pos.myrot - 180)) * RAD) * STEP;
	w->pos.my_y = w->pos.my_y - cos((90 - (w->pos.myrot - 180)) * RAD) * STEP;
	if (w->pos.my_x - floor(w->pos.my_x) < NEAR_FLOOR)
		if (w->map.plan[fieldnr - 1] == '1')
			w->pos.my_x = floor(old_posX) + NEAR_FLOOR;
	if (w->pos.my_y - floor(w->pos.my_y) < NEAR_FLOOR)
		if (w->map.plan[fieldnr - w->map.nr_cols] == '1')
			w->pos.my_y = floor(old_posY) + NEAR_FLOOR;
	if (floor(old_posX) != floor(w->pos.my_x))
		if (w->map.plan[fieldnr - 1] == '1')
			w->pos.my_x = old_posX;
	if (floor(old_posY) != floor(w->pos.my_y))
		if (w->map.plan[fieldnr - w->map.nr_cols] == '1')
			w->pos.my_y = old_posY;
	if (w->pos.my_x - floor(w->pos.my_x) < NEAR_FLOOR
		&& w->pos.my_y - floor(w->pos.my_y) < NEAR_FLOOR
		&& w->map.plan[fieldnr - 1] != '1'
		&& w->map.plan[fieldnr - w->map.nr_cols] != '1'
		&& w->map.plan[fieldnr - w->map.nr_cols - 1] == '1')
		w->pos.my_y = ceil(w->pos.my_y) - NEAR_FLOOR;
}

void	new_position_d_q4(float old_posX, float old_posY, t_window *w)
{
	int	fieldnr;

	fieldnr = (int)(floor(w->pos.my_x) + floor(w->pos.my_y) * w->map.nr_cols);
	w->pos.my_x = w->pos.my_x + cos((90 - (w->pos.myrot - 270)) * RAD) * STEP;
	w->pos.my_y = w->pos.my_y - sin((90 - (w->pos.myrot - 270)) * RAD) * STEP;
	if (w->pos.my_x - floor(w->pos.my_x) > NEAR_CEIL)
		if (w->map.plan[fieldnr + 1] == '1')
			w->pos.my_x = floor(old_posX) - NEAR_FLOOR;
	if (w->pos.my_y - floor(w->pos.my_y) < NEAR_FLOOR)
		if (w->map.plan[fieldnr - w->map.nr_cols] == '1')
			w->pos.my_y = floor(old_posY) + NEAR_FLOOR;
	if (floor(old_posX) != floor(w->pos.my_x))
		if (w->map.plan[fieldnr + 1] == '1')
			w->pos.my_x = old_posX;
	if (floor(old_posY) != floor(w->pos.my_y))
		if (w->map.plan[fieldnr - w->map.nr_cols] == '1')
			w->pos.my_y = old_posY;
	if (w->pos.my_x - floor(w->pos.my_x) > NEAR_CEIL
		&& w->pos.my_y - floor(w->pos.my_y) < NEAR_FLOOR
		&& w->map.plan[fieldnr + 1] != '1'
		&& w->map.plan[fieldnr - w->map.nr_cols] != '1'
		&& w->map.plan[fieldnr - w->map.nr_cols + 1] == '1')
		w->pos.my_y = ceil(w->pos.my_y) - NEAR_FLOOR;
}

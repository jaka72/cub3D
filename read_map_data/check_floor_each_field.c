/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_floor_each_field.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 14:47:43 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/08 10:00:03 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	check_field(char *plan, int *i, t_window *w)
{
	if (plan[*i - 1] == '*' || plan[*i - 1] == ' '
		|| plan[*i + 1] == '*' || plan[*i + 1] == ' ')
		return (error(-1, "Error\n Map hole on right side\n"));
	if (plan[*i - w->map.nr_cols] == '*'
		|| plan[*i - w->map.nr_cols] == ' ')
		return (error(-1, "Error\n Map has a hole b)! \n"));
	if (plan[*i + w->map.nr_cols] == '*'
		|| plan[*i + w->map.nr_cols] == ' ')
		return (error(-1, "\nError\n Map has a hole c)! \n"));
	if (plan[*i - w->map.nr_cols - 1] == '*'
		|| plan[*i - w->map.nr_cols - 1] == ' ')
		return (error(-1, "Error\n Field hole on upper-left\n"));
	if (plan[*i - w->map.nr_cols + 1] == '*'
		|| plan[*i - w->map.nr_cols + 1] == ' ')
		return (error(-1, "Error\n Field hole on upper-right\n"));
	if (plan[*i + w->map.nr_cols - 1] == '*'
		|| plan[*i + w->map.nr_cols - 1] == ' ')
		return (error(-1, "Error\n Field hole on lower-left\n"));
	if (plan[*i + w->map.nr_cols + 1] == '*'
		|| plan[*i + w->map.nr_cols + 1] == ' ')
		return (error(-1, "Error\n Field hole on lower-right \n"));
	return (0);
}

// CHECKING FOR HOLES AROUND EACH EMPTY FIELD
// last row can't be checked with +cols ...
// left and right of each field, must not be '*' or 'space'
int	check_holes_around_field(char *plan, int *i, t_window *w)
{
	*i = w->map.nr_cols;
	while (*i < (w->map.nr_rows - 1) * w->map.nr_cols)
	{
		if (plan[*i] == '0' || plan[*i] == w->map.positioner)
		{
			if (check_field(plan, i, w) < 0)
				return (-1);
		}
		(*i)++;
	}
	return (0);
}

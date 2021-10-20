/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_floor_plan.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 13:26:35 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:16:56 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	check_first_and_last_line(char *plan, int *i, t_window *w)
{
	*i = 0;
	while (*i < w->map.nr_cols)
	{
		if (plan[*i] != '1' && plan[*i] != ' ' && plan[*i] != '*')
			return (error(-1, "Error\n Illegal character in first line\n"));
		(*i)++;
	}
	*i = (w->map.nr_rows - 1) * w->map.nr_cols;
	while (*i < w->map.nr_rows * w->map.nr_cols)
	{
		if (plan[*i] != '1' && plan[*i] != ' ' && plan[*i] != '*')
			return (error(-1, "Error\n Illegal character in last line\n"));
		(*i)++;
	}
	return (0);
}

// CHECK EACH FIRST FIELD IN EACH ROW
int	check_each_first_and_last_field(char *plan, int *i, int *j, t_window *w)
{
	*i = 0;
	while (*i < w->map.nr_cols * w->map.nr_rows)
	{
		*j = *i;
		while (plan[*j] == ' ')
			(*j)++;
		if (plan[*j] != '1')
			return (error(-1, "\nMap has no wall on the west side!\n"));
		*i = *i + w->map.nr_cols;
	}
	*i = w->map.nr_cols - 1;
	while (*i < w->map.nr_cols * w->map.nr_rows)
	{
		if (plan[*i] == '0' || plan[*i] == w->map.positioner)
			return (error(-1, "\nMap has a hole on the east side!\n"));
		*i = *i + w->map.nr_cols;
	}
	return (0);
}

int	check_holes_on_north_and_south_side(char *plan, int *i, t_window *w)
{
	*i = 0;
	while (*i < w->map.nr_cols)
	{
		if (plan[*i] == '0')
			return (error(-1, "Error\n Map has a hole on the north side! \n"));
		(*i)++;
	}
	*i = (w->map.nr_rows - 1) * w->map.nr_cols;
	while (*i < w->map.nr_rows * w->map.nr_cols)
	{
		if (plan[*i] == '0')
			return (error(-1, "Error\n Map has a hole on the south side!\n"));
		(*i)++;
	}
	return (0);
}

// CHECK FOR ILLEGAL CHARS IN WHOLE PLAN, OTHER THAN N, W, E ...
// STARTS ONLY AT THE 2nd LINE
int	check_illegal_chars_in_floor_plan(char *plan, int *i, t_window *w)
{
	*i = w->map.nr_cols;
	while (*i < (w->map.nr_rows - 1) * w->map.nr_cols)
	{
		if (plan[*i] != ' ' && plan[*i] != '0' && plan[*i] != '1'
			&& plan[*i] != 'N' && plan[*i] != 'E' && plan[*i] != 'S'
			&& plan[*i] != 'W' && plan[*i] != '*' && plan[*i] != '2')
			return (error(-1, "Error\n Illegal character in floor plan.\n"));
		if (plan[*i] == '2' && w->topdown == 0)
			return (error(-1, "Error\n Sprite in floor plan, outside bonus\n"));
		(*i)++;
	}
	return (0);
}

// j, separate index to check paralely, not to ruin the i value
int	check_floor_plan(char *plan, t_window *w)
{
	int	ret;
	int	j;
	int	i;

	ret = check_illegal_chars_in_floor_plan(plan, &i, w);
	if (ret < 0)
		return (-1);
	ret = check_holes_around_field(plan, &i, w);
	if (ret < 0)
		return (-1);
	ret = check_first_and_last_line(plan, &i, w);
	if (ret < 0)
		return (-1);
	ret = check_each_first_and_last_field(plan, &i, &j, w);
	if (ret < 0)
		return (-1);
	ret = check_holes_on_north_and_south_side(plan, &i, w);
	if (ret < 0)
		return (-1);
	return (0);
}

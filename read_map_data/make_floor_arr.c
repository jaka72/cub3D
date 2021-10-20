/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_floor_arr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 13:23:24 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/06 18:11:05 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

// because first round the plan is NULL !
// i COUNTS NR CHARS SO FAR FROM PREVIOUS plan
// FREE OLD plan IF IT IS NOT NULL,
void	copy_old_plan_to_temp(char *line, char *temp_all, t_window *w)
{
	w->index.i = 0;
	while (w->index.i < w->map.nr_fields)
	{
		if (w->map.plan != NULL)
		{
			temp_all[w->index.i] = w->map.plan[w->index.i];
			w->index.i++;
		}
	}
	w->index.j = ft_strlen(line);
	if (w->index.j > w->map.longest_line)
		w->map.longest_line = w->index.j;
	w->map.nr_fields = w->map.nr_fields + w->index.j + 1;
	if (w->map.plan != NULL)
	{
		free(w->map.plan);
		w->map.plan = NULL;
	}
}

void	copy_temp_to_fresh_plan(char *temp_all, t_window *w)
{
	w->index.k = 0;
	while (w->index.k < w->index.i)
	{
		w->map.plan[w->index.k] = temp_all[w->index.k];
		w->index.k++;
	}
}

// APPEND NEW LINE TO EXISTING PLAN
void	append_newline_to_plan(char *line, t_window *w)
{
	w->index.i = 0;
	while (w->index.i < w->index.j)
	{
		w->map.plan[w->index.k] = line[w->index.i];
		w->index.k++;
		w->index.i++;
	}
	w->map.plan[w->index.k] = '\n';
}

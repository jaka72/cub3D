/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_data_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 15:52:57 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:57:30 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	set_mypos(char *plan, t_window *w)
{
	int	i;

	i = 0;
	while (i < w->map.nr_rows * w->map.nr_cols)
	{
		if (plan[i] == 'N' || plan[i] == 'E' || plan[i] == 'S'
			|| plan[i] == 'W')
		{
			if (plan[i] == 'N')
				w->pos.myrot = 0;
			else if (plan[i] == 'E')
				w->pos.myrot = 90;
			else if (plan[i] == 'S')
				w->pos.myrot = 180;
			else if (plan[i] == 'W')
				w->pos.myrot = 270;
			w->pos.my_x = i % w->map.nr_cols + 0.5;
			w->pos.my_y = i / w->map.nr_cols + 0.5;
			return (0);
		}
		i++;
	}
	return (0);
}

void	reset_map_data(t_window *w)
{
	w->data.resol_width = 0;
	w->data.resol_height = 0;
	w->data.floor_red = -1;
	w->data.floor_green = -1;
	w->data.floor_blue = -1;
	w->data.sky_red = -1;
	w->data.sky_green = -1;
	w->data.sky_blue = -1;
	w->map.nr_rows = 0;
	w->map.nr_cols = 0;
	w->map.longest_line = 0;
	w->map.plan = NULL;
	w->map.nr_fields = 0;
}

int	check_tex_suffix(t_window *w)
{
	if (check_suffix(w->data.no_path) < 0)
		return (-1);
	if (check_suffix(w->data.so_path) < 0)
		return (-1);
	if (check_suffix(w->data.ea_path) < 0)
		return (-1);
	if (check_suffix(w->data.we_path) < 0)
		return (-1);
	return (0);
}

void	save_final_values(t_window *w)
{
	w->map.nr_cols = w->map.longest_line;
	w->map.nr_fields = w->map.nr_cols * w->map.nr_rows;
	w->map.plan = w->map.plan2;
	w->map.nr_cols = w->map.longest_line;
	w->data.sky_color = w->data.sky_red * 65536 + w->data.sky_green * 256
		+ w->data.sky_blue;
	w->data.floor_color = w->data.floor_red * 65536 + w->data.floor_green * 256
		+ w->data.floor_blue;
}

int	get_texture_paths(char *line, int i, t_window *w)
{
	if (line[i] == 'S' && line[i + 1] == ' ')
		return (get_path_string(line + i + 2, &w->data.sprite_path));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (get_path_string(line + i + 2, &w->data.no_path));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (get_path_string(line + i + 2, &w->data.so_path));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (get_path_string(line + i + 2, &w->data.ea_path));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (get_path_string(line + i + 2, &w->data.we_path));
	return (0);
}

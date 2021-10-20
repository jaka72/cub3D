/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_paths_and_colors.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 19:31:08 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:17:08 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	get_sky_rgb(char *line, int *r, int *g, int *b)
{
	int	i;
	int	ret;

	check_first_chars(line, &i, r, 'C');
	ret = get_value(line, &i, r, g);
	if (ret < 0)
		return (error(-1, "Error\n Sky color not valid.\n"));
	ret = get_value(line, &i, g, b);
	if (ret < 0)
		return (error(-1, "Error\n Sky color not valid.\n"));
	calculate_value(line, &i, b);
	ret = check_chars_at_end(line, &i);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255
		|| *b < 0 || *b > 255 || ret < 0)
		return (error(-1, "Error\n The Sky color is invalid or missing.\n"));
	while (line[i])
	{	
		if (line[i] != ' ' && line[i] != '\0')
			return (error(-1, "Error\n Illegal ch. in Sky color value.\n"));
		i++;
	}
	return (0);
}

int	get_sky_rgb_or_path(t_window *w, char *line, int i)
{
	if (w->data.sky_istex == 0 && (w->topdown == 0 || w->topdown == 1))
	{
		w->data.sky_path = NULL;
		return (get_sky_rgb(line, &w->data.sky_red,
				&w->data.sky_green, &w->data.sky_blue));
	}
	else if (w->data.sky_istex == 1 && w->topdown == 0)
		return (error(-1, "Error\n Sky should have rgb values\n"));
	else if (w->data.sky_istex == 1 && w->topdown == 1)
		return (get_path_string(line + i + 2, &w->data.sky_path));
	return (0);
}

int	get_floor_rgb(char *line, int *r, int *g, int *b)
{
	int	i;
	int	ret;

	check_first_chars(line, &i, r, 'F');
	ret = get_value(line, &i, r, g);
	if (ret < 0)
		return (error(-1, "Error\n Floor color not valid.\n"));
	ret = get_value(line, &i, g, b);
	if (ret < 0)
		return (error(-1, "Error\n Floor color not valid.\n"));
	calculate_value(line, &i, b);
	ret = check_chars_at_end(line, &i);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255
		|| *b < 0 || *b > 255 || ret < 0)
		return (error(-1, "Error\n The Floor color is invalid or missing.\n"));
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\0')
			return (error(-1, "Error\n  Illegal ch. in Floor color value.\n"));
		i++;
	}
	return (0);
}

int	get_floor_color_main(t_window *w, char *line)
{
	if (w->data.floor_istex == 0 && (w->topdown == 0
			|| w->topdown == 1))
		return (get_floor_rgb(line, &w->data.floor_red,
				&w->data.floor_green, &w->data.floor_blue));
	else if (w->data.floor_istex == 1 && w->topdown == 0)
		return (error(-1, "Error\n Floor should have rgb values\n"));
	else if (w->data.floor_istex == 1 && w->topdown == 1)
		return (give_color(w));
	return (0);
}

int	get_resol_and_floor_sky_values(char *line, int *i, t_window *w)
{
	if (line[*i] == 'R' && line[*i + 1] == ' ')
		return (get_resol(line, w));
	else if (line[*i] == 'F' && line[*i + 1] == ' ')
	{
		if (get_floor_color_main(w, line) < 0)
			return (-1);
	}
	else if (line[*i] == 'C' && line[*i + 1] == ' ')
	{
		if (get_sky_rgb_or_path(w, line, *i) < 0)
			return (-1);
	}
	return (0);
}

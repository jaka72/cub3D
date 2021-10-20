/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 19:31:26 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:17:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	get_floor_plan(char *line, t_window *w)
{
	char	*temp_all;

	temp_all = malloc(w->map.nr_fields * sizeof(char));
	if (temp_all == NULL)
		return (-1);
	copy_old_plan_to_temp(line, temp_all, w);
	w->map.plan = malloc((w->map.nr_fields) * sizeof(char));
	if (w->map.plan == NULL)
	{
		free(temp_all);
		return (-1);
	}
	copy_temp_to_fresh_plan(temp_all, w);
	append_newline_to_plan(line, w);
	free(temp_all);
	temp_all = NULL;
	w->index.i = 0;
	return (0);
}

// ALL FUNCTION CALLS NEED ARGUMENT line + 2,
//     TO SKIP THE INICIAL 2 LETTERS, BEFORE ./
static int	process_line(char *line, t_window *w)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			;
		else if (line[i] == 'S' || line[i] == 'N'
			|| line[i] == 'E' || line[i] == 'W')
			return (get_texture_paths(line, i, w));
		else if (ft_isdigit(line[i]))
		{
			get_floor_plan(line, w);
			w->map.nr_rows++;
			return (0);
		}
		else
			return (get_resol_and_floor_sky_values(line, &i, w));
		i++;
	}
	return (0);
}

int	loop_and_process_lines(char *line, int fd, t_window *w)
{
	int	ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(&line, fd);
		if (process_line(line, w) < 0)
		{
			free(line);
			line = NULL;
			return (-1);
		}
		free(line);
		line = NULL;
	}
	return (0);
}

void	free_paths(t_window *w)
{
	free(w->data.no_path);
	free(w->data.ea_path);
	free(w->data.so_path);
	free(w->data.we_path);
	free(w->map.plan2);
	if (w->topdown == 1 && w->data.sky_istex == 1)
		free(w->data.sky_path);
}

int	read_map_data(char *file, t_window *w)
{
	char	*line;
	int		fd;

	if (check_map_file(file, w) < 0)
		return (error(-1, ""));
	reset_map_data(w);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_close_fd(-1, fd, "Error\n Error opening the map file\n"));
	line = NULL;
	if (loop_and_process_lines(line, fd, w) < 0)
		return (error_close_fd(-1, fd, ""));
	close(fd);
	w->map.nr_fields--;
	insert_walls(w);
	free(w->map.plan);
	save_final_values(w);
	check_tex_suffix(w);
	if (check_floor_plan(w->map.plan, w) < 0)
	{
		free_paths(w);
		return (error(-1, ""));
	}
	set_mypos(w->map.plan, w);
	return (0);
}

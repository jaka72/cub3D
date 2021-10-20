/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_file.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 11:41:59 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:24:06 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_file.h"

// check always the first char. It must be valid.
// found '1'  begin reading floor plan
// HERE HANDLED CHARS AFTER FLOOR PLAN
int	check_identifiers(char *line, t_window *w)
{
	int	ret;

	if (line[0] != ' ' && line[0] != '\0')
	{
		if (w->map.floor_found == TRUE && w->value.is_empty == TRUE)
			return (error(-1, "Error\n Illegal character after floor plan!\n"));
		ret = check_first_char(line, w);
		if (ret == -1)
			return (error(-1, "Error\n Issue at beginning of line\n"));
		else if (ret == 1)
			return (1);
	}
	else
	{
		ret = check_other_chars(line, w);
		if (ret < 0)
			return (error(-1, "Error\n Illegal character in line.\n"));
		else if (ret == 1)
			return (1);
	}
	return (ret);
}

int	check_identifiers_and_floor_plan(char *line, t_window *w)
{
	int	ret;

	ret = check_identifiers(line, w);
	if (ret == -1)
	{
		free(line);
		line = NULL;
		return (-1);
	}
	else if (ret == 1)
	{
		if (count_positioners_and_sprites(line, w) == -1)
		{
			free(line);
			line = NULL;
			return (-1);
		}
	}
	free(line);
	line = NULL;
	return (0);
}

int	check_file_suffix(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	while (file[i] == ' ')
		i--;
	if (file[i] != 'b' || file[i - 1] != 'u' || file[i - 2] != 'c'
		|| file[i - 3] != '.')
		return (error(-1, "Error\n Map file suffix is not correct\n"));
	return (0);
}

int	check_map_file(char *file, t_window *w)
{
	char	*line;
	int		fd;
	int		ret;
	int		ret_gnl;

	ret = open_file_and_reset_flags(w, file, &fd, &ret_gnl);
	if (ret < 0 || check_file_suffix(file) < 0)
		return (error_close_fd(-1, fd, ""));
	line = NULL;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(&line, fd);
		if (ret_gnl < 0)
		{
			free(line);
			line = NULL;
			break ;
		}
		if (check_identifiers_and_floor_plan(line, w) == -1)
			return (error_close_fd(-1, fd, ""));
	}
	if (check_identifiers_and_close_file(fd, w) == -1)
		return (-1);
	return (0);
}

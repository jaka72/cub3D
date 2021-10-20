/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_chars_in_line.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/19 11:19:22 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/17 13:23:56 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_file.h"

void	check_if_rgb_or_path(char *line, int i, char c, t_window *w)
{
	i++;
	while (line[i] == ' ')
		i++;
	if (c == 'C')
	{
		if (!ft_isdigit(line[i]))
			w->data.sky_istex = 1;
		w->value.ceil++;
	}
	else if (c == 'F')
	{
		if (!ft_isdigit(line[i]))
			w->data.floor_istex = 1;
		w->value.floor++;
	}
}

// it means it can't check for chars before the first key
int	check_first_char(char *line, t_window *w)
{
	if (line[0] == '1')
	{
		w->map.floor_found = TRUE;
		return (1);
	}
	if (line[0] == 'R' && line[1] == ' ')
		w->value.resol++;
	else if (line[0] == 'S' && line[1] == ' ')
		w->value.sprite++;
	else if (line[0] == 'F' && line[1] == ' ')
		check_if_rgb_or_path(line, 0, 'F', w);
	else if (line[0] == 'C' && line[1] == ' ')
		check_if_rgb_or_path(line, 0, 'C', w);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		w->value.no++;
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		w->value.so++;
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		w->value.ea++;
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		w->value.we++;
	else
		return (error(-1, ""));
	return (0);
}

// WHEN floor_found == TRUE, SIGNAL TO STOP 1ST LOOP, START CHECKING FLOOR PLAN
int	check_other_chars_2(char *line, int *i, t_window *w)
{
	if (line[*i] == 'N' && line[*i + 1] == 'O'
		&& line[*i + 2] == ' ' && line[*i - 1] == ' ')
		w->value.no++;
	else if (line[*i] == 'S' && line[*i + 1] == 'O'
		&& line[*i + 2] == ' ' && line[*i - 1] == ' ')
		w->value.so++;
	else if (line[*i] == 'E' && line[*i + 1] == 'A'
		&& line[*i + 2] == ' ' && line[*i - 1] == ' ')
		w->value.ea++;
	else if (line[*i] == 'W' && line[*i + 1] == 'E'
		&& line[*i + 2] == ' ' && line[*i - 1] == ' ')
		w->value.we++;
	else if (line[*i] == '\0')
		;
	else if (line[*i] == '1')
	{
		w->map.floor_found = TRUE;
		return (1);
	}
	else
		return (error(-1, ""));
	return (0);
}

int	check_other_chars_1(char *line, int *i, t_window *w)
{
	int	ret;

	if (line[*i] == 'R' && line[*i + 1] == ' ' && line[*i - 1] == ' ')
		w->value.resol++;
	else if (line[*i] == 'S' && line[*i + 1] == ' ' && line[*i - 1] == ' ')
		w->value.sprite++;
	else if (line[*i] == 'F' && line[*i + 1] == ' ' && line[*i - 1] == ' ')
		check_if_rgb_or_path(line, *i, line[*i], w);
	else if (line[*i] == 'C' && line[*i + 1] == ' ' && line[*i - 1] == ' ')
		check_if_rgb_or_path(line, *i, line[*i], w);
	else
	{	
		ret = check_other_chars_2(line, i, w);
		if (ret < 0)
			return (-1);
		else if (ret == 1)
			return (1);
	}
	return (0);
}

int	check_other_chars(char *line, t_window *w)
{
	int	i;
	int	ret;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0' && w->map.floor_found == TRUE)
		w->value.is_empty = TRUE;
	if (w->map.floor_found == TRUE && w->value.is_empty == TRUE
		&& line[i] != '\0')
		return (error(-1, "Error\n Illegal character after floor plan\n"));
	ret = check_other_chars_1(line, &i, w);
	if (ret == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	return (0);
}

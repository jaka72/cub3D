/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_colors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 16:25:39 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 12:51:01 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	check_chars_at_end(char *line, int *i)
{
	while (!ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		if (line[*i] != ' ')
			return (error(-1, "Error\n Illegal chars at end of line\n"));
		(*i)++;
	}
	return (0);
}

int	check_chars_btw_values(char *line, int *i)
{
	int	comma;

	comma = 0;
	while (!ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		if (line[*i] != ' ' && line[*i] != ',')
			return (error(-1, "Error\n Illegal chars between values\n"));
		if (line[*i] == ',')
			comma++;
		(*i)++;
	}
	if (comma != 1)
		return (error(-1, ""));
	return (0);
}

int	check_first_chars(char *line, int *i, int *color, char identifier)
{
	*i = 0;
	while (!ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		if (line[*i] != ' ' && line[*i] != identifier)
			return (error(-1, "Error\n Illegal chars at start of line\n"));
		(*i)++;
	}
	if (ft_isdigit(line[*i]))
		*color += 1;
	return (0);
}

void	calculate_value(char *line, int *i, int *color)
{
	while (ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		*color = *color * 10 + (line[*i] - '0');
		(*i)++;
	}
}

int	get_value(char *line, int *i, int *color, int *next_color)
{
	int	ret;

	calculate_value(line, i, color);
	if (line[*i] != ',' && line[*i] != ' ')
		return (-1);
	ret = check_chars_btw_values(line, i);
	if (ret < 0)
		return (-1);
	if (ft_isdigit(line[*i]))
		*next_color = 0;
	return (0);
}

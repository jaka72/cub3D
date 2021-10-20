/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_colors_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:57:09 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 11:53:37 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	check_suffix(char *path)
{
	int		len;
	char	*substr;

	len = ft_strlen(path);
	len = len - 4;
	substr = ft_substr(path, len, 4);
	if (ft_strncmp(substr, ".xpm", 4) != 0)
	{
		free(substr);
		return (error(-1, ""));
	}
	free(substr);
	substr = NULL;
	return (0);
}

int	give_color(t_window *w)
{
	w->data.floor_red = 123;
	w->data.floor_green = 123;
	w->data.floor_blue = 80;
	return (0);
}

void	read_line(char *line, int *i, int *j)
{
	*i = 0;
	while (line[*i] == ' ')
		(*i)++;
	*j = 0;
	while (line[*i])
	{
		(*i)++;
		(*j)++;
	}
	(*i)--;
	(*j)--;
	if (line[*i] == ' ')
	{
		while (line[*i] == ' ')
		{
			(*i)--;
			(*j)--;
		}
	}
	(*i)++;
	(*j)++;
}

int	get_path_string(char *line, char **s)
{
	int	i;
	int	j;

	read_line(line, &i, &j);
	*s = malloc((j + 1) * sizeof(char));
	if (s == NULL)
		return (-1);
	(*s)[j] = '\0';
	j--;
	i--;
	while (j >= 0)
	{
		(*s)[j] = line[i];
		j--;
		i--;
	}
	return (0);
}

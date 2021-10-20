/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_resol.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 16:39:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/08 10:00:08 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

int	get_resol_width(char *line, int *i, t_window *w)
{
	while (!ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		if (line[*i] != ' ' && line[*i] != 'R')
			return (error(-1, "Error\n  Illegal ch. in resolution value.\n"));
		(*i)++;
	}
	while (ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		w->data.resol_width = w->data.resol_width * 10 + (line[*i] - '0');
		(*i)++;
	}
	while (!ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		if (line[*i] != ' ' && line[*i])
			return (error(-1, "Error\n  Illegal ch. in resolution value.\n"));
		(*i)++;
	}
	return (0);
}

int	get_resol_height(char *line, int *i, t_window *w)
{
	while (ft_isdigit(line[*i]) && line[*i] != '\0')
	{
		w->data.resol_height = w->data.resol_height * 10 + (line[*i] - '0');
		(*i)++;
	}
	while (line[*i])
	{
		if (line[*i] != ' ' && line[*i] != '\0')
			return (error(-1, "Error\n  Illegal ch. in resolution value.\n"));
		(*i)++;
	}
	return (0);
}

int	get_resol(char *line, t_window *w)
{
	int	i;
	int	ret;

	i = 0;
	ret = get_resol_width(line, &i, w);
	if (ret < 0)
		return (-1);
	ret = get_resol_height(line, &i, w);
	if (ret < 0)
		return (-1);
	if (w->data.resol_height == 0 || w->data.resol_width == 0)
		return (error(-1, "Error\n  Resolution is 0 or not defined.\n"));
	return (0);
}

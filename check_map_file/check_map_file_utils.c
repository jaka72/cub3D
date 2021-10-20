/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_file_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 18:45:31 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:25:38 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check_map_file.h"

// These flags indicate existence of each config identifier / value
//	w->value.map = 0;    // maybe not used
// ADDED: _paths = NULL, IT WAS GIVING SEGFAULT, WAS NEVER INITIALIZED TO NULL
void	reset_flags(t_window *w)
{
	w->value.resol = 0;
	w->value.sprite = 0;
	w->value.floor = 0;
	w->value.ceil = 0;
	w->value.no = 0;
	w->value.so = 0;
	w->value.ea = 0;
	w->value.we = 0;
	w->map.field_size = 0;
	w->value.is_empty = FALSE;
	w->data.floor_istex = 0;
	w->data.sky_istex = 0;
	w->map.floor_found = FALSE;
	w->map.count_positioners = 0;
	w->map.count_sprites = 0;
	w->data.floor_path = NULL;
	w->data.sky_path = NULL;
	w->data.sprite_path = NULL;
}

int	open_file_and_reset_flags(t_window *w, char *file, int *fd, int *ret_gnl)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (error(-1, "Error\n File descriptor < 0\n"));
	*ret_gnl = 1;
	reset_flags(w);
	return (0);
}

int	count_positioners_and_sprites(char *line, t_window *w)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			;
		else if (line[i] == 'N' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'S')
		{
			w->map.count_positioners++;
			w->map.positioner = line[i];
		}
		else if (line[i] == '2')
			w->map.count_sprites++;
		i++;
	}
	return (0);
}

int	check_if_all_identifiers_present(t_window *w)
{
	if (w->value.floor != 1 || w->value.ceil != 1)
		return (error(-1, ""));
	if (w->value.so != 1 || w->value.ea != 1 || w->value.we != 1
		|| w->value.no != 1)
		return (error(-1, ""));
	if (w->value.sprite > 0 && w->topdown == 0)
		return (error(-1, "Error\n Sprite identifier present, outside bonus!\n"));
	if (w->value.sprite > 1 && w->topdown == 1)
		return (error(-1, "Error\n The sprite identifier repeated!\n"));
	return (0);
}

int	check_identifiers_and_close_file(int fd, t_window *w)
{
	if (check_if_all_identifiers_present(w) == -1)
	{
		close(fd);
		return (error(-1, "Error\n Identifier missing or repeated.\n"));
	}
	if (w->map.count_positioners != 1)
	{
		close(fd);
		return (error(-1, "Error\n Positioner missing or repeated.\n"));
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_walls.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/06 14:20:44 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/08 10:00:12 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map_data.h"

void	allocate_wall_map(int *i, int *j, int *k, t_window *w)
{
	w->map.plan2 = malloc((w->map.longest_line * w->map.nr_rows)
			* sizeof(char));
	if (!w->map.plan2)
		return ;
	*i = 0;
	*j = 0;
	*k = 0;
}

void	insert_walls(t_window *w)
{
	int	i;
	int	j;
	int	k;

	allocate_wall_map(&i, &j, &k, w);
	while (j < (w->map.longest_line * w->map.nr_rows))
	{
		if (w->map.plan[i] != '\n')
		{
			w->map.plan2[j] = w->map.plan[i];
			j++;
			k++;
		}
		else
		{
			while (k < w->map.longest_line)
			{
				w->map.plan2[j] = '*';
				j++;
				k++;
			}
			k = 0;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map_info.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 13:48:42 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 12:59:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_info_1(t_window *w)
{
	ft_printf(YEL"\n ______________________________________\n"RES);
	ft_printf(YEL"\n           MAP INFO:\n\n"RES);
	ft_printf("  Identifiers present: R%d, F%d, C%d, NO%d, SO%d, EA%d, WE%d, \
		S%d\n", w->value.resol, w->value.floor, w->value.ceil, w->value.no,
		w->value.so, w->value.ea, w->value.we, w->value.sprite);
	ft_printf("  nr_fields:       %d\n", w->map.nr_fields);
	ft_printf("  nr_cols:         %d\n", w->map.nr_cols);
	ft_printf("  nr_rows:         %d\n", w->map.nr_rows);
	ft_printf("  longest fl. line: %d\n", w->map.longest_line);
	ft_printf("  field_width:     %d\n", w->map.field_width);
	ft_printf("  field_size:      %d\n", w->map.field_size);
	ft_printf("  bonus on/off:    %d\n", w->topdown);
	ft_printf("  scr-res-width:   %d\n", w->data.screen_width);
	ft_printf("  scr-res-height:  %d\n", w->data.screen_height);
	ft_printf("  win-res-width:   %d\n", w->data.resol_width);
	ft_printf("  win-res-height:  %d\n", w->data.resol_height);
	ft_printf("  endian:          %d\n\n", w->tex.no.endian);
}

void	print_map_info_2(t_window *w)
{
	ft_printf("  floor rgb:       %3d, %3d, %3d\n",
		w->data.floor_red, w->data.floor_green, w->data.floor_blue);
	ft_printf("  sky rgb:         %3d, %3d, %3d\n\n",
		w->data.sky_red, w->data.sky_green, w->data.sky_blue);
	ft_printf("  north-texture:   [%s]\n", w->data.no_path);
	ft_printf("  east-texture:    [%s]\n", w->data.ea_path);
	ft_printf("  south-texture:   [%s]\n", w->data.so_path);
	ft_printf("  west-texture:    [%s]\n", w->data.we_path);
	ft_printf("  sky-texture:     [%s]\n", w->data.sky_path);
	ft_printf("  floor texture:   [%s]\n", w->data.floor_path);
	ft_printf("  sprite-texture:  [%s]\n", w->data.sprite_path);
	ft_printf("  count_sprites:     %d\n", w->map.count_sprites);
	ft_printf("  count_positioners: %d\n", w->map.count_positioners);
}

void	print_map_string(t_window *w)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < w->map.nr_fields)
	{
		if (w->map.plan[i] == ' ')
			ft_printf(".");
		else
		{
			if (w->map.plan2[i] == '1')
				ft_printf(BLUBH CYN"%c"RES, w->map.plan2[i]);
			else if (w->map.plan2[i] == '0')
				ft_printf(BLU"%c"RES, w->map.plan2[i]);
			else
				ft_printf("%c", w->map.plan2[i]);
		}
		if (i == j * w->map.nr_cols - 1)
		{
			ft_printf("\n");
			j++;
		}
		i++;
	}
}

void	print_map_info(t_window *w)
{
	ft_printf(YEL"\n ______________________________________\n"RES);
	ft_printf(YEL"\n       MAP SAVED TO t_map.plan_2:\n\n"RES);
	print_map_string(w);
	print_map_info_1(w);
	print_map_info_2(w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_data.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 17:18:17 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 12:50:40 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_DATA_H
# define READ_MAP_DATA_H

# include "../cub3d.h"

// read map data.c
int		read_map_data(char *file, t_window *w);

// read map data utils.c
int		set_mypos(char *plan, t_window *w);
void	reset_map_data(t_window *w);
int		check_tex_suffix(t_window *w);
void	save_final_values(t_window *w);
int		get_texture_paths(char *line, int i, t_window *w);

// get resol.c
int		get_resol(char *line, t_window *w);

// check floor plan
int		check_first_and_last_line(char *plan, int *i, t_window *w);
int		check_each_first_and_last_field(char *plan, int *i, int *j,
			t_window *w);
int		check_holes_on_north_and_south_side(char *plan, int *i, t_window *w);
int		check_illegal_chars_in_floor_plan(char *plan, int *i, t_window *w);

// check floor each field.c
int		check_floor_plan(char *plan, t_window *w);
int		check_holes_around_field(char *plan, int *i, t_window *w);

// get paths and colors.c
int		get_floor_color(char *line, int *r, int *g, int *b);
int		get_sky_color(char *line, int *r, int *g, int *b);
int		get_path_string(char *line, char **s);
int		get_resol_and_floor_sky_values(char *line, int *i, t_window *w);

// make floor.c
void	copy_old_plan_to_temp(char *line, char *temp_all, t_window *w);
void	copy_temp_to_fresh_plan(char *temp_all, t_window *w);
void	append_newline_to_plan(char *line, t_window *w);

// read map colors.c
int		check_chars_btw_values(char *line, int *i);
int		check_chars_at_end(char *line, int *i);
int		check_first_chars(char *line, int *i, int *color, char identifier);
void	calculate_value(char *line, int *i, int *rgb);
int		get_value(char *line, int *i, int *color, int *next_color);

// read map colors utils.c
int		give_color(t_window *w);
int		check_suffix(char *path);

// instert walls.c
void	insert_walls(t_window *w);

#endif

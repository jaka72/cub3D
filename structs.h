/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:18:07 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 12:52:34 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_distance
{
	float	hor;
	float	ver;
}	t_distance;

typedef struct s_keys
{
	int	arrow_right;
	int	arrow_left;
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}	t_keys;

typedef struct s_colors
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_colors;

typedef struct s_conf_values
{
	int	resol;
	int	sprite;
	int	floor;
	int	ceil;
	int	no;
	int	so;
	int	ea;
	int	we;
	int	is_empty;
}	t_values;

// plan:  here are all lines, separated with '\n'
// plan2: in here it's copied from plan, now padded with
//        walls '1' to make lines evenly long
typedef struct s_map
{
	int		nr_rows;
	int		nr_cols;
	int		nr_fields;
	int		field_width;
	int		field_size;
	char	*plan;
	char	*plan2;
	int		longest_line;
	char	positioner;
	int		count_positioners;
	int		count_sprites;
	int		floor_found;
}	t_map;

// *sprite_path: it is needed in case of path present
typedef struct s_data
{
	int				screen_width;
	int				screen_height;
	int				resol_width;
	int				resol_height;
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	int				sky_red;
	int				sky_green;
	int				sky_blue;
	unsigned int	sky_color;
	unsigned int	floor_color;
	char			*no_path;
	char			*we_path;
	char			*so_path;
	char			*ea_path;
	char			*sky_path;
	char			*floor_path;
	int				sky_istex;
	int				floor_istex;
	char			*sprite_path;
}	t_data;

typedef struct s_floor_indexes
{
	int	i;
	int	j;
	int	k;
}	t_indexes;

typedef struct s_hits
{
	float	x;
	float	y;
	float	xh;
	float	yh;
	float	xv;
	float	yv;
	float	op;
	float	adj;
	int		field;
	int		color;
	float	dpp;
	int		slice_x;
	int		slice_y;
	int		wall_side;
	float	wall_height;
}	t_hits;

// current_quadrant: keep track of which quadrant, 
//     used to decide which texture, no, so , ea, we
typedef struct s_positions
{
	int		start_quad;
	int		current_quad;
	float	my_x;
	float	my_y;
	float	fov_step;
	int		myrot;
}	t_position;

// **codes: codes for each color (each element is a string of symbols)
// *colors: each element is a hex_number. Order is corresponding to
//		the codes array
// *tex_str: string with the hole plan (symbols) // it can be freed
//		after tex_arr is filled
// **tex_sym_arr: array of strings, each is a group of symbols
// All these can be freed after all data is read into each t_texEA.map
typedef struct s_temp
{
	char			**codes;
	int				nr_colors;
	unsigned int	*colors;
	char			*tex_str;
	char			**tex_sym_arr;
}	t_temp;

// cpc: chars per color
// i: counts nr of symbols per color
// x: DETERMINES WHICH TEXTURE WILL BE USED IN A SLICE (east or west ...)
// *map: array of the whole map with hex_colors
typedef struct s_texx
{
	void			*mlx;
	void			*img;
	char			*addr;
	int				endian;
	int				line_length;
	int				bits_per_pixel;
	int				x;
	int				rows;
	int				cols;
	int				cpc;
	int				i;
	unsigned int	*map;
}	t_texx;

typedef struct s_textures
{
	t_texx	ea;
	t_texx	we;
	t_texx	no;
	t_texx	so;
	t_texx	sky;
	t_texx	sprite;
}	t_textures;

// *img = MINIMAP TOPDOWN
// *img02 = ONLY FRONTVIEW, NO MINIMAP
typedef struct s_windows
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	void			*img02;
	void			*addr02;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				key[6];
	int				topdown;
	t_keys			keys;
	t_distance		dist;
	t_colors		color;
	t_position		pos;
	t_values		value;
	t_map			map;
	t_data			data;
	t_indexes		index;
	t_hits			hit;
	t_temp			temp;
	t_textures		tex;
}	t_window;

#endif

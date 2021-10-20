/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 13:44:49 by jaka          #+#    #+#                 */
/*   Updated: 2021/10/17 16:18:36 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx_mac/mlx.h"

# include "./structs.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./main_utils/main_utils.h"
# include "./check_map_file/check_map_file.h"
# include "./read_map_data/read_map_data.h"
# include "./get_hits/get_hits.h"
# include "./get_new_position/get_new_position.h"
# include "./get_next_line/get_next_line.h"
# include "./read_texture/read_texture.h"
# include "./bonus/bonus.h"

# ifdef __linux__
#  define SYSTEM 'l'
#  define RED_CROSS_CODE 33
#  include <X11/Xlib.h>
# endif
# ifdef __APPLE__
#  define SYSTEM 'a'
#  define RED_CROSS_CODE 17
#  include <CoreGraphics/CGDisplayConfiguration.h>
# endif

# define RAD 0.01745
# define FOV 60.0
# define TRUE 1
# define FALSE 0

# define STEP 0.1
# define NEAR_FLOOR 0.5
# define NEAR_CEIL 0.5

// 0[d], 1[a], 2[w], 3[s], 4[<--], 5[-->]
# define RIGHT 0
# define LEFT 1
# define FORW 2
# define BACKW 3
# define ROT_LEFT 4
# define ROT_RIGHT 5

// hit.wall_side
# define HOR 1
# define VER 2

void	draw_fov_hits(t_window *window);
void	print_sky(t_window *window);
void	print_floor(t_window *window);
void	get_field_size(t_window *w);
void	get_hits(t_window *window, float angle_i);
void	draw_fov(t_window *window);
int		render(t_window *window);
void	distance_hor(t_window *window, float op, float angle);
void	distance_ver(t_window *window, float op, float angle);
void	set_quadrant_and_angle(t_window *window, float *angle_i);
void	calc_wall_height(float distance, float angle, t_texx *t_tex,
			t_window *w);

int		exit_cross(t_window *window);
int		error(int n, char *msg);
int		error_close_fd(int n, int fd, char *msg);
int		close_and_free(t_window *window);

void	print_map_info(t_window *window);

# define BLKB  "\e[40m"
# define HYEL  "\e[0;93m"
# define HGRN  "\e[0;92m"
# define HWHT  "\e[0;97m"
# define YEL   "\e[0;33m"
# define RED   "\x1B[31m"
# define REDB  "\e[41m"
# define GRN   "\x1B[32m"
# define LGRN  "\e[0;92m"
# define BLUBH "\e[44m"
# define BLUB  "\e[1;36m"
# define BLU   "\e[0;34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RES   "\x1B[0m"

#endif
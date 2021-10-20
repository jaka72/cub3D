/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/01 18:10:55 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 13:54:20 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_slice(t_window *w, float dist, float angle, t_texx *t_tex)
{
	int		i;
	float	j;
	int		jj;
	float	k;
	float	step;

	calc_wall_height(dist, angle, t_tex, w);
	i = 0;
	j = t_tex->x;
	jj = j;
	step = t_tex->cols / w->hit.wall_height;
	w->hit.slice_y = (int)(w->data.resol_height / 2 - w->hit.wall_height / 2);
	k = 0;
	while (i < (int)w->hit.wall_height)
	{
		w->hit.color = t_tex->map[(int)(floor(j))];
		if (w->hit.slice_x >= 0 && w->hit.slice_x < w->data.resol_width
			&& w->hit.slice_y >= 0 && w->hit.slice_y < w->data.resol_height)
			my_pixel_put_front(w, w->hit.slice_x, w->hit.slice_y, w->hit.color);
		k = k + step;
		j = jj + (floor(k) * t_tex->rows);
		w->hit.slice_y++;
		i++;
	}
	t_tex->x++;
}

void	print_closer(t_window *w, float angle)
{
	if (w->dist.hor < w->dist.ver)
	{
		w->hit.wall_side = HOR;
		if (w->pos.current_quad == 4 || w->pos.current_quad == 1)
			print_slice(w, w->dist.hor, angle, &w->tex.no);
		else
			print_slice(w, w->dist.hor, angle, &w->tex.so);
	}
	else
	{
		w->hit.wall_side = VER;
		if (w->pos.current_quad == 3 || w->pos.current_quad == 4)
			print_slice(w, w->dist.ver, angle, &w->tex.we);
		else
			print_slice(w, w->dist.ver, angle, &w->tex.ea);
	}
}

void	draw_fov(t_window *w)
{
	float	angle;
	float	angle_i;

	if (w->data.sky_istex == 1)
		print_sky_xpm(w);
	else
		print_sky(w);
	print_floor(w);
	set_quadrant_and_angle(w, &angle_i);
	w->hit.slice_x = 0;
	angle = -30;
	while (w->hit.slice_x < w->data.resol_width)
	{
		get_hits(w, angle_i);
		print_closer(w, angle);
		angle_i = angle_i + w->pos.fov_step;
		angle = angle + w->pos.fov_step;
		w->hit.slice_x++;
	}
	if (w->map.field_size != 0)
	{
		draw_map(w);
		draw_grid(w);
		draw_hands(w, w->pos.myrot);
	}
}

void	get_resol_and_init_mlx(t_window *window)
{
	window->map.field_width = 1;
	window->width = window->data.resol_width;
	window->height = window->data.resol_height;
	check_screen_resol(window);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width,
			window->height, "Cube3D");
	window->img = mlx_new_image(window->mlx, window->width, window->height);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_length, &window->endian);
	window->img02 = mlx_new_image(window->mlx, window->width, window->height);
	window->addr02 = mlx_get_data_addr(window->img02, &window->bits_per_pixel,
			&window->line_length, &window->endian);
	get_field_size(window);
}

// Red cross code is different: Mac 17, Linux 33
// 	system("leaks cub3D");   // only for Mac
int	main(int argc, char **argv)
{
	t_window	window;

	if (argc != 2)
		return (error(-1, "Error\n Number of arguments should be 2\n"));
	topdown_view(1, &window);
	if (read_map_data(argv[1], &window) == -1)
		exit(0);
	get_resol_and_init_mlx(&window);
	if (read_all_textures(&window) < 0)
		exit(0);
	window.pos.fov_step = FOV / window.data.resol_width;
	window.hit.dpp = (window.data.resol_width / 2) / tan(30 * RAD);
	mlx_hook(window.win, 2, (1L << 0), &key_press, &window);
	mlx_hook(window.win, 3, (1L << 1), &key_release, &window);
	mlx_hook(window.win, RED_CROSS_CODE, 1L << 17, &exit_cross, &window);
	mlx_loop_hook(window.mlx, &render, &window);
	init_keys(&window);
	choose_keys(&window);
	print_map_info(&window);
	mlx_loop(window.mlx);
	return (0);
}

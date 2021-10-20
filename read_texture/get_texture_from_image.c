/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture_from_image.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/31 12:14:58 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/20 13:45:27 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_texture.h"

// colors r and g need to be shifted to the left, ie: 
//      0x0000FF   =>  0xFF0000
void	get_colors(t_texx *tex, t_window *w, int x, int y)
{
	if (tex->endian == 1)
	{
		w->color.t = (int)tex->addr[(y * tex->line_length) + x];
		w->color.r = (int)tex->addr[(y * tex->line_length) + x + 1];
		w->color.g = (int)tex->addr[(y * tex->line_length) + x + 2];
		w->color.b = (int)tex->addr[(y * tex->line_length) + x + 3];
	}
	else
	{
		w->color.t = (int)*(tex->addr + ((y * tex->line_length) + x + 3));
		w->color.r = (int)*(tex->addr + ((y * tex->line_length) + x + 2));
		w->color.g = (int)*(tex->addr + ((y * tex->line_length) + x + 1));
		w->color.b = (int)*(tex->addr + ((y * tex->line_length) + x));
	}
	if (w->color.r < 0)
//		w->color.r = (w->color.r - 0xffffff00) * 0x10000;
		w->color.r = (w->color.r - 0xffffff00) << 16;
	else
//		w->color.r = w->color.r * 0x10000;
		w->color.r = w->color.r << 16;

	if (w->color.g < 0)
//		w->color.g = (w->color.g - 0xffffff00) * 0x100;
		w->color.g = (w->color.g - 0xffffff00) << 8;
	else
//		w->color.g = w->color.g * 0x100;
		w->color.g = w->color.g << 8;
	if (w->color.b < 0)
		w->color.b = w->color.b - 0xffffff00;
}

int	get_image_data(t_window *window, char *path, t_texx *tex)
{
	tex->img = mlx_xpm_file_to_image(window->mlx, path, &tex->rows, &tex->cols);
	if (tex->img == NULL)
		return (error(-1, "Error\n Texture path is wrong or does not exist.\n"));
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	tex->map = malloc(sizeof(int) * tex->rows * tex->cols);
	if (tex->map == NULL)
		return (-1);
	return (0);
}

int	get_texture_from_image(t_window *w, char *path, t_texx *tex)
{
	int		i;
	int		y;
	int		x;

	if (get_image_data(w, path, tex) == -1)
		return (-1);
	i = 0;
	y = 0;
	while (y < tex->cols)
	{
		x = 0;
		while (x < tex->rows * 4)
		{
			get_colors(tex, w, x, y);
			tex->map[i] = w->color.r + w->color.g + w->color.b;
			x += 4;
			i++;
		}
		y++;
	}
	i = 0;
	y = 0;
	return (0);
}

int	read_all_textures(t_window *w)
{
	if ((get_texture_from_image(w, w->data.no_path, &w->tex.no) < 0))
		return (error(-1, ""));
	if ((get_texture_from_image(w, w->data.ea_path, &w->tex.ea) < 0))
		return (error(-1, ""));
	if ((get_texture_from_image(w, w->data.we_path, &w->tex.we) < 0))
		return (error(-1, ""));
	if ((get_texture_from_image(w, w->data.so_path, &w->tex.so) < 0))
		return (error(-1, ""));
	if (w->topdown == 1 && w->data.sky_istex == 1)
	{
		if ((get_texture_from_image(w, w->data.sky_path, &w->tex.sky) < 0))
			return (error(-1, ""));
	}
	return (0);
}

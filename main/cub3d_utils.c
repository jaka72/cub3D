/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/03 12:39:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 16:14:03 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	topdown_view(int top, t_window *window)
{
	window->topdown = 0;
	if (top == 1)
		window->topdown = 1;
}

int	error(int n, char *msg)
{
	ft_printf("%s\n", msg);
	return (n);
}

int	error_close_fd(int n, int fd, char *msg)
{
	close(fd);
	ft_printf("%s\n", msg);
	return (n);
}

int	exit_cross(t_window *window)
{
	close_and_free(window);
	return (0);
}

int	close_and_free(t_window *window)
{
	free(window->tex.no.map);
	free(window->tex.so.map);
	free(window->tex.ea.map);
	free(window->tex.we.map);
	free(window->map.plan2);
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_image(window->mlx, window->img02);
	exit(0);
}

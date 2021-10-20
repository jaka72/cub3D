/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:17:46 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:23:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	set_flag_left(void)
{
	if (t_cnt.width < 0)
	{
		if (t_cnt.prec < 0)
			t_cnt.prec = 1;
		t_fl.left = 1;
		t_cnt.width = t_cnt.width * -1;
	}
	else if (t_cnt.width > 0 && t_cnt.prec < 0
		&& t_fl.dot == 1)
	{
		if (t_fl.zero_w == 1)
			t_cnt.prec = -1;
		else
			t_cnt.prec = 1;
	}
}

static void	set_flag_zero(int xlen)
{
	if (t_val.x == 0 && t_cnt.prec == 0)
	{
		t_cnt.width++;
		t_fl.zero_w = 0;
	}
	if (t_cnt.prec <= xlen && t_cnt.prec >= 0)
		t_fl.zero_w = 0;
	if (t_cnt.prec < 0 && t_fl.dot == 1)
		t_cnt.prec = 1;
}

void	print_x(void)
{
	int	xlen;

	xlen = ft_getlen_hex(t_val.x);
	set_flag_left();
	set_flag_zero(xlen);
	if (t_fl.left == 0)
		print_x_right();
	if (t_fl.left == 1)
		print_x_left();
}

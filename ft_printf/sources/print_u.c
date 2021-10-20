/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:14:39 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:23:10 by jaka          ########   odam.nl         */
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
	else if (t_cnt.width > 0 && t_cnt.prec < 0 && t_fl.dot == 1)
	{
		if (t_fl.zero_w == 1)
			t_cnt.prec = -1;
		else
			t_cnt.prec = 1;
	}
}

static void	set_flag_zero(void)
{
	if (t_val.u == 0 && t_cnt.prec == 0)
	{
		t_cnt.width++;
		t_fl.zero_w = 0;
	}
	if (t_cnt.prec <= ft_getlen(t_val.u) && t_cnt.prec >= 0)
		t_fl.zero_w = 0;
	if (t_cnt.prec < 0 && t_fl.dot == 1)
		t_cnt.prec = 1;
}

void	print_u(void)
{
	if (t_val.u < 0)
		t_val.u = 4294967296 + t_val.u;
	set_flag_left();
	set_flag_zero();
	if (t_fl.left == 0)
		print_u_right();
	if (t_fl.left == 1)
		print_u_left();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d0.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:03:07 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:21:22 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	set_flag_zero(void)
{
	if (t_fl.dot == 1 && t_cnt.prec >= 0 && t_fl.zero_w == 1)
		t_fl.zero_w = 0;
}

static void	set_flag_left(void)
{
	if (t_cnt.prec < 0)
		t_cnt.prec = 1;
	if (t_cnt.width < 0)
	{
		t_cnt.width = t_cnt.width * -1;
		t_fl.left = 1;
	}
	if (t_cnt.width > 0 && t_cnt.prec < 0
		&& t_fl.dot == 1)
		t_cnt.prec = 1;
	if (t_val.d == 0 && t_cnt.prec == 0)
		t_cnt.width++;
}

void	print_d0(void)
{
	set_flag_zero();
	set_flag_left();
	if (t_fl.left == 0)
		print_d0_right();
	if (t_fl.left == 1)
	{
		if (t_fl.dot == 0)
		{
			ft_putnbr(t_val.d);
			while (t_cnt.width > ft_getlen(t_val.d))
				put_and_substract(&t_cnt.width, ' ');
		}
		else if (t_fl.dot == 1)
		{
			while (t_cnt.prec > ft_getlen(t_val.d))
			{
				put_and_substract(&t_cnt.prec, '0');
				t_cnt.width--;
			}
			ft_putnbr(t_val.d);
			while (t_cnt.width > ft_getlen(t_val.d))
				put_and_substract(&t_cnt.width, ' ');
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d0_right.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:01:06 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:21:47 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	case_1(int dlen)
{
	while (t_cnt.width > dlen)
	{
		if (t_fl.zero_w == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t_cnt.width--;
	}
	ft_putnbr(t_val.d);
}

static void	case_2(int dlen)
{
	while (t_cnt.width > t_cnt.prec)
	{
		if (t_fl.zero_w == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t_cnt.width--;
	}
	while (t_cnt.prec > dlen)
		put_and_substract(&t_cnt.prec, '0');
	ft_putnbr(t_val.d);
}

void	print_d0_right(void)
{
	int	dlen;

	dlen = ft_getlen(t_val.d);
	if (t_cnt.width <= dlen && t_fl.dot == 0)
		ft_putnbr(t_val.d);
	else if ((t_cnt.width <= dlen && t_fl.dot == 1)
		|| t_cnt.width <= t_cnt.prec)
	{
		while (t_cnt.prec > dlen)
			put_and_substract(&t_cnt.prec, '0');
		ft_putnbr(0);
	}
	else if (t_cnt.width > dlen && (t_fl.dot == 0 || t_cnt.prec == 0))
		case_1(dlen);
	else if (t_cnt.width > t_cnt.prec && t_cnt.prec >= dlen)
		case_2(dlen);
}

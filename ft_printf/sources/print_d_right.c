/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_right.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 19:54:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:22:53 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	case_1(int dlen)
{
	if (t_val.d >= 0 && t_fl.space == 1)
		put_and_substract(&t_cnt.width, ' ');
	if (t_val.d < 0 && t_fl.zero_w == 1)
		put_and_substract(&t_cnt.width, '-');
	if (t_val.d < 0 && t_fl.zero_w == 0)
		t_cnt.width--;
	while (t_cnt.width > dlen)
	{
		if (t_fl.zero_w == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		t_cnt.width--;
	}
	if (t_val.d < 0 && t_fl.zero_w == 0)
		put_and_substract(&t_cnt.width, '-');
	ft_putnbr(t_val.d);
}

static void	case_2(int dlen)
{
	if (t_val.d < 0)
		t_cnt.width--;
	while (t_cnt.width > t_cnt.prec)
		put_and_substract(&t_cnt.width, ' ');
	if (t_cnt.width < t_cnt.prec && t_fl.space == 1)
		ft_putchar(' ');
	if (t_val.d < 0)
		ft_putchar('-');
	while (t_cnt.prec > dlen)
		put_and_substract(&t_cnt.prec, '0');
	ft_putnbr(t_val.d);
}

void	print_d_right(void)
{
	int	dlen;

	dlen = ft_getlen(t_val.d);
	if (t_cnt.prec <= dlen)
		case_1(dlen);
	else if (t_cnt.prec > dlen)
		case_2(dlen);
}

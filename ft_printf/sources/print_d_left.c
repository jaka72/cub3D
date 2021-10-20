/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_left.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 19:54:02 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:22:41 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	case_1(int dlen)
{
	if (t_fl.space == 1 && t_val.d >= 0)
		ft_putchar(' ');
	if (t_val.d < 0)
		ft_putchar('-');
	while (t_cnt.prec > dlen)
		put_and_substract(&t_cnt.prec, '0');
	ft_putnbr(t_val.d);
}

static void	case_2(int dlen)
{
	if (t_fl.space == 1)
		put_and_substract(&t_cnt.width, ' ');
	if (t_val.d < 0)
		put_and_substract(&t_cnt.width, '-');
	while (t_cnt.prec > dlen)
	{
		put_and_substract(&t_cnt.prec, '0');
		t_cnt.width--;
	}
	ft_putnbr(t_val.d);
	while (t_cnt.width > dlen)
		put_and_substract(&t_cnt.width, ' ');
}

void	print_d_left(void)
{
	int	dlen;

	dlen = ft_getlen(t_val.d);
	if (t_cnt.width <= dlen)
		case_1(dlen);
	else if (t_cnt.width > dlen)
		case_2(dlen);
}

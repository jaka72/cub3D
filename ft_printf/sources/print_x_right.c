/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x_right.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:16:56 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 20:16:56 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_x_right(void)
{
	int	xlen;

	xlen = ft_getlen_hex(t_val.x);
	if (t_cnt.width <= xlen && t_cnt.prec <= xlen)
		ft_putnbr_hex(t_val.x);
	else if (t_cnt.width > xlen && t_cnt.prec <= xlen)
	{
		while (t_cnt.width > xlen)
		{
			if (t_fl.zero_w == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			t_cnt.width--;
		}
		ft_putnbr_hex(t_val.x);
	}
	else
	{
		while (t_cnt.width > t_cnt.prec)
			put_and_substract(&t_cnt.width, ' ');
		while (t_cnt.prec > xlen)
			put_and_substract(&t_cnt.prec, '0');
		ft_putnbr_hex(t_val.x);
	}
}

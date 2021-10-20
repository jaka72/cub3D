/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u_right.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:13:47 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:23:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_u_right(void)
{
	int	ulen;

	ulen = ft_getlen(t_val.u);
	if (t_cnt.width <= ulen && t_cnt.prec <= ulen)
		ft_putnbr_long(t_val.u);
	else if (t_cnt.width > ulen && t_cnt.prec <= ulen)
	{
		while (t_cnt.width > ft_getlen(t_val.u))
		{
			if (t_fl.zero_w == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			t_cnt.width--;
		}
		ft_putnbr_long(t_val.u);
	}
	else if (t_cnt.prec > ulen)
	{
		while (t_cnt.width > t_cnt.prec)
			put_and_substract(&t_cnt.width, ' ');
		while (t_cnt.prec > ft_getlen(t_val.u))
			put_and_substract(&t_cnt.prec, '0');
		ft_putnbr_long(t_val.u);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x_left.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:16:15 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:24:06 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_x_left(void)
{
	int	xlen;

	xlen = ft_getlen_hex(t_val.x);
	if (t_cnt.width <= xlen && t_cnt.prec <= xlen)
		ft_putnbr_hex(t_val.x);
	else
	{
		while (t_cnt.prec > xlen)
		{
			put_and_substract(&t_cnt.prec, '0');
			t_cnt.width--;
		}
		ft_putnbr_hex(t_val.x);
		while (t_cnt.width > xlen)
			put_and_substract(&t_cnt.width, ' ');
	}
}

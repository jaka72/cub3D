/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u_left.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:13:02 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 20:13:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_u_left(void)
{
	while (t_cnt.prec > ft_getlen(t_val.u))
	{
		put_and_substract(&t_cnt.prec, '0');
		t_cnt.width--;
	}
	ft_putnbr_long(t_val.u);
	while (t_cnt.width > ft_getlen(t_val.u))
		put_and_substract(&t_cnt.width, ' ');
}

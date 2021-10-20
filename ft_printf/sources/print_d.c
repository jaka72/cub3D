/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 19:56:25 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 19:56:25 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_d(void)
{
	if (t_cnt.prec < 0)
		t_cnt.prec = 1;
	else if (t_cnt.prec >= 0 && t_fl.dot == 1 && t_fl.zero_w == 1)
		t_fl.zero_w = 0;
	if (t_cnt.width < 0)
	{
		t_cnt.width = t_cnt.width * -1;
		t_fl.left = 1;
	}
	if (t_fl.left == 0)
		print_d_right();
	else if (t_fl.left == 1)
		print_d_left();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 19:53:12 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 19:53:12 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(void)
{
	if (t_cnt.width < 0)
	{
		t_cnt.width = t_cnt.width * -1;
		t_fl.left = 1;
	}
	if (t_fl.left == 0)
	{
		while (t_cnt.width > 1)
		{
			if (t_fl.zero_w == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			t_cnt.width--;
		}
		ft_putchar(t_val.c);
	}
	else if (t_fl.left == 1)
	{
		ft_putchar(t_val.c);
		while (t_cnt.width > 1)
			put_and_substract(&t_cnt.width, ' ');
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_p.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:09:05 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 20:09:05 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p_null(void)
{
	if (t_fl.left == 0)
	{
		while (t_cnt.width > 3)
		{
			ft_putchar(' ');
			t_cnt.width--;
		}
		ft_putstr("0x0");
	}
	if (t_fl.left == 1)
	{
		ft_putstr("0x0");
		while (t_cnt.width > 3)
			put_and_substract(&t_cnt.width, ' ');
	}
}

void	print_p_right(unsigned long up, int newlen)
{
	if (t_fl.zero_w == 1)
	{
		if (t_fl.space == 1)
			put_and_substract(&t_cnt.width, ' ');
		ft_putstr("0x");
		while (t_cnt.width > newlen)
			put_and_substract(&t_cnt.width, '0');
		ft_putnbr_hex(up);
	}
	else
	{
		while (t_cnt.width > newlen)
			put_and_substract(&t_cnt.width, ' ');
		ft_putstr("0x");
		ft_putnbr_hex(up);
	}
}

void	print_p_left(unsigned long up, int newlen)
{
	if (t_fl.space == 1)
		put_and_substract(&t_cnt.width, ' ');
	ft_putstr("0x");
	ft_putnbr_hex(up);
	while (t_cnt.width > newlen)
		put_and_substract(&t_cnt.width, ' ');
}

void	print_p(void)
{
	unsigned long	up;
	int				newlen;

	if (t_cnt.width < 0)
	{
		t_fl.left = 1;
		t_cnt.width = t_cnt.width * -1;
	}
	if (t_val.p == NULL)
	{
		print_p_null();
		return ;
	}
	up = (unsigned long)t_val.p;
	newlen = ft_getlen_hex(up) + 2;
	if (t_fl.left == 0)
		print_p_right(up, newlen);
	if (t_fl.left == 1)
		print_p_left(up, newlen);
}

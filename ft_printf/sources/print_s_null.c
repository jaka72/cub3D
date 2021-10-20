/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_s_null.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:10:42 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 20:10:42 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_null_right(int slen)
{
	if (t_cnt.prec == 0)
		while (t_cnt.width > 0)
			put_and_substract(&t_cnt.width, ' ');
	else if (t_cnt.prec > 0 && t_cnt.prec <= slen)
	{
		t_cnt.width = t_cnt.width - t_cnt.prec;
		while (t_cnt.width > 0)
			put_and_substract(&t_cnt.width, ' ');
		ft_putstr_precision(t_val.s, t_cnt.prec);
	}
	else
	{
		t_cnt.width = t_cnt.width - slen;
		while (t_cnt.width > 0)
			put_and_substract(&t_cnt.width, ' ');
		ft_putstr_precision(t_val.s, t_cnt.prec);
	}
}

void	print_null_left(int slen)
{
	ft_putstr_precision(t_val.s, t_cnt.prec);
	if (t_fl.dot == 1 && t_cnt.prec < t_cnt.width && t_cnt.prec <= slen)
		t_cnt.width = t_cnt.width - t_cnt.prec;
	else
		t_cnt.width = t_cnt.width - slen;
	while (t_cnt.width > 0)
		put_and_substract(&t_cnt.width, ' ');
}

void	print_s_null(void)
{
	t_val.s = "(null)";
	if (t_cnt.width < 0)
	{
		t_cnt.width = t_cnt.width * -1;
		t_fl.left = 1;
	}
	if (t_cnt.prec < 0 && t_fl.dot == 1)
		t_cnt.prec = ft_strlen(t_val.s);
	if (t_fl.left == 0)
		print_null_right(ft_strlen(t_val.s));
	else if (t_fl.left == 1)
		print_null_left(ft_strlen(t_val.s));
}

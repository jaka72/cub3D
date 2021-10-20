/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_s.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:12:09 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/13 20:12:09 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_s_right(int slen)
{
	if ((t_fl.dot == 0 || t_cnt.prec > slen))
	{
		t_cnt.width = t_cnt.width - slen;
		while (t_cnt.width > 0)
			put_and_substract(&t_cnt.width, ' ');
		ft_putstr_precision(t_val.s, t_cnt.prec);
	}
	else if (t_cnt.prec == 0)
		while (t_cnt.width > 0)
			put_and_substract(&t_cnt.width, ' ');
	else if (t_cnt.prec > 0 && t_cnt.prec <= slen)
	{
		t_cnt.width = t_cnt.width - t_cnt.prec;
		while (t_cnt.width > 0)
			put_and_substract(&t_cnt.width, ' ');
		ft_putstr_precision(t_val.s, t_cnt.prec);
	}
}

void	print_s_left(int slen)
{
	ft_putstr_precision(t_val.s, t_cnt.prec);
	if (t_fl.dot == 1 && t_cnt.prec < t_cnt.width && t_cnt.prec <= slen)
		t_cnt.width = t_cnt.width - t_cnt.prec;
	else
		t_cnt.width = t_cnt.width - slen;
	while (t_cnt.width > 0)
		put_and_substract(&t_cnt.width, ' ');
}

void	print_s(void)
{
	if (t_val.s == NULL)
	{
		print_s_null();
		return ;
	}
	if (t_cnt.width < 0)
	{
		t_cnt.width = t_cnt.width * -1;
		t_fl.left = 1;
	}
	if (t_cnt.prec < 0 && t_fl.dot == 1)
		t_cnt.prec = ft_strlen(t_val.s);
	if (t_fl.left == 0)
		print_s_right(ft_strlen(t_val.s));
	else if (t_fl.left == 1)
		print_s_left(ft_strlen(t_val.s));
}

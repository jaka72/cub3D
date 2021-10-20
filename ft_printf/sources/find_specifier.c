/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_specifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 13:01:00 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/14 13:01:00 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	store_argument(va_list args)
{
	if (t_cnt.specifier == 'd')
		t_val.d = va_arg(args, int);
	else if (t_cnt.specifier == 'u')
		t_val.u = va_arg(args, unsigned);
	else if (t_cnt.specifier == 'c')
		t_val.c = va_arg(args, int);
	else if (t_cnt.specifier == 's')
		t_val.s = va_arg(args, char *);
	else if (t_cnt.specifier == 'x')
		t_val.x = va_arg(args, unsigned);
	else if (t_cnt.specifier == 'X')
		t_val.x = va_arg(args, unsigned);
	else if (t_cnt.specifier == 'p')
		t_val.p = va_arg(args, void *);
	else if (t_cnt.specifier == '%')
		t_val.c = '%';
}

void	find_specifier(char str, va_list args)
{
	if (str == 'd' || str == 'i')
		t_cnt.specifier = 'd';
	else if (str == 'u')
		t_cnt.specifier = 'u';
	else if (str == 'c')
		t_cnt.specifier = 'c';
	else if (str == 's')
		t_cnt.specifier = 's';
	else if (str == 'x')
		t_cnt.specifier = 'x';
	else if (str == 'X')
		t_cnt.specifier = 'X';
	else if (str == 'p')
		t_cnt.specifier = 'p';
	else if (str == '%')
		t_cnt.specifier = '%';
	store_argument(args);
}

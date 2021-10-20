/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:18:25 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:17:50 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_all(void)
{
	t_fl.left = 0;
	t_fl.space = 0;
	t_fl.zero_w = 0;
	t_fl.zero_p = 0;
	t_fl.star_w = 0;
	t_fl.star_p = 0;
	t_fl.dot = 0;
	t_cnt.width = 0;
	t_cnt.specifier = '0';
	t_cnt.prec = -1;
}

void	process_char(const char **str, va_list args)
{
	while (**str != 'c' && **str != 's' && **str != 'd' && **str != 'i'
		&& **str != 'x' && **str != 'X' && **str != 'u' && **str != 'p')
	{
		check_flags(str, args);
		if (**str == '%')
			return ;
		*str = *str + 1;
	}
}

void	print_result(void)
{
	if (t_cnt.specifier == 'c')
		print_c();
	else if ((t_cnt.specifier == 'd' || t_cnt.specifier == 'i') && t_val.d != 0)
		print_d();
	else if ((t_cnt.specifier == 'd' || t_cnt.specifier == 'i') && t_val.d == 0)
		print_d0();
	else if (t_cnt.specifier == 'u')
		print_u();
	else if (t_cnt.specifier == 's')
		print_s();
	else if (t_cnt.specifier == 'x' || t_cnt.specifier == 'X')
		print_x();
	else if (t_cnt.specifier == 'p')
		print_p();
	else if (t_cnt.specifier == '%')
		print_c();
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	t_cnt.ch_printed = 0;
	while (*str != '\0')
	{
		if (*str != '%')
			ft_putchar(*str);
		else if (*str == '%' && *(str + 1) == '%')
		{
			ft_putchar('%');
			str++;
		}
		else if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			reset_all();
			process_char(&str, args);
			find_specifier(*str, args);
			print_result();
		}
		str++;
	}
	va_end(args);
	return (t_cnt.ch_printed);
}

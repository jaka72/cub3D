/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 12:51:28 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/14 12:51:28 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_flag(const char str, va_list args)
{
	if (str == '-')
		t_fl.left = 1;
	else if (str == ' ')
		t_fl.space = 1;
	else if (str == '0' && t_fl.zero_w == 0)
		t_fl.zero_w = 1;
	else if (str == '*' && t_fl.dot == 0)
	{
		t_fl.star_w = 1;
		t_cnt.width = va_arg(args, int);
	}
	else if (str == '*' && t_fl.dot == 1)
	{
		t_fl.star_p = 1;
		t_cnt.prec = va_arg(args, int);
	}
	else if (str == '.')
		t_fl.dot = 1;
}

void	check_flags(const char **str, va_list args)
{
	if (**str == '-' || (**str == '0' && t_cnt.width == 0)
		|| **str == ' ' || **str == '.' || **str == '*')
	{
		set_flag(**str, args);
		if (**str == '.' || (**str == '.' && *(*str + 1) == 's')
			|| (**str == '.' && *(*str + 1) == '0'))
			t_cnt.prec = 0;
	}
	if (ft_isdigit(**str) && **str != '0' && t_fl.dot == 0)
		t_cnt.width = t_cnt.width * 10 + (**str - 48);
	else if (**str == '0' && t_cnt.width > 0 && t_fl.dot == 0)
		t_cnt.width = t_cnt.width * 10;
	else if (ft_isdigit(**str) && **str != '0' && t_fl.dot == 1)
		t_cnt.prec = t_cnt.prec * 10 + (**str - 48);
	else if (**str == '0' && t_cnt.prec > 0 && t_fl.dot == 1)
		t_cnt.prec = t_cnt.prec * 10;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_precision.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 10:32:48 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/10/31 10:32:48 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_precision(char *s, int precision)
{
	if (!s)
		return ;
	if (precision == 0 && t_fl.dot == 1)
		write(1, s, 0);
	else if (precision > 0 && precision < ft_strlen(s))
	{
		write(1, s, precision);
		t_cnt.ch_printed = t_cnt.ch_printed + precision;
	}
	else if (t_cnt.prec >= ft_strlen(s))
	{
		write(1, s, ft_strlen(s));
		t_cnt.ch_printed = t_cnt.ch_printed + ft_strlen(s);
	}
	else if (precision < 0)
	{
		write(1, s, ft_strlen(s));
		t_cnt.ch_printed = t_cnt.ch_printed + ft_strlen(s);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_long.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 11:46:20 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:22:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_long(long unsigned int n)
{
	long unsigned int	num;

	num = (long unsigned int)n;
	if (num == 0 && t_cnt.prec == 0)
		return ;
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

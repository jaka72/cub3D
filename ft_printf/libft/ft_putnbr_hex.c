/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 13:38:53 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:20:28 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	store_hex(int *i, unsigned long *x, int arr[])
{
	int	rem;

	while (*x / 16 != 0)
	{
		rem = *x % 16;
		if (rem <= 15 && rem >= 10 && t_cnt.specifier == 'x')
			*arr = rem + 87;
		else if (rem <= 15 && rem >= 10 && t_cnt.specifier == 'X')
			*arr = rem + 55;
		else if (rem <= 15 && rem >= 10 && t_cnt.specifier == 'p')
			*arr = rem + 87;
		else if (rem < 10)
			*arr = rem + '0';
		*x = *x / 16;
		*i = *i + 1;
		arr++;
	}
}

void	ft_putnbr_hex(unsigned long x)
{
	int	arr[20];
	int	i;

	if (x == 0 && t_cnt.prec == 0)
		return ;
	i = 0;
	store_hex(&i, &x, arr);
	if (x <= 9)
		ft_putchar(x + '0');
	else if (x >= 10 && t_cnt.specifier == 'x')
		ft_putchar(x + 87);
	else if (x >= 10 && t_cnt.specifier == 'X')
		ft_putchar(x + 55);
	else if (x >= 10 && t_cnt.specifier == 'p')
		ft_putchar(x + 87);
	i--;
	while (i >= 0)
	{
		ft_putchar(arr[i]);
		i--;
	}
}

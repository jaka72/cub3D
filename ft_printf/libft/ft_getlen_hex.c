/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getlen_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 11:46:20 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:19:24 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_getlen_hex(unsigned long x)
{
	int	i;

	i = 0;
	while (x / 16 != 0)
	{
		x = x / 16;
		i++;
	}
	return (i + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 11:46:20 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:19:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_getlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
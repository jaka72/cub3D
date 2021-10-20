/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_and_substract.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 13:35:31 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/14 13:35:31 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_and_substract(int *n, char c)
{
	ft_putchar(c);
	*n = *n - 1;
}

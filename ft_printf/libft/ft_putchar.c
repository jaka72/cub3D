/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 11:32:34 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/11/02 11:32:34 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** ADAPTED FOR FPRINT
*/

void	ft_putchar(int c)
{
	write(1, &c, 1);
	t_cnt.ch_printed++;
}

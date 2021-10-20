/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ispath.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/07 11:41:22 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/19 11:37:06 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// WHICH CHARS ARE GOOD TO BE IN A TEXTURE PATH ?
int	ft_ispath(int c)
{
	if (c >= 46 && c <= 126)
		return (1);
	else
		return (0);
}

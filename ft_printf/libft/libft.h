/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 13:27:35 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/02/14 13:27:35 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../ft_printf.h"

int				ft_strlen(const char *str);
void			ft_putchar(int c);
int				ft_isdigit(int c);
void			ft_putnbr(int n);
void			ft_putnbr_long(long unsigned int n);
void			ft_putnbr_hex(unsigned long x);
int				ft_getlen(long nbr);
int				ft_getlen_hex(unsigned long x);
void			ft_putstr_precision(char *s, int precision);
void			put_and_substract(int *n, char c);
void			ft_putstr(char *s);
#endif

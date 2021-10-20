/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 20:26:39 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/17 12:18:30 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

struct	s_counts
{
	int		width;
	int		prec;
	char	specifier;
	int		ch_printed;
}		t_cnt;

struct	s_values
{
	char			c;
	char			*s;
	int				d;
	unsigned int	x;
	int long		u;
	size_t			*p;
}		t_val;

struct	s_flags
{
	int	left;
	int	space;
	int	zero_w;
	int	zero_p;
	int	star_w;
	int	star_p;
	int	dot;
}		t_fl;

int		ft_printf(const char *str, ...);
void	check_flags(const char **str, va_list args);
void	find_specifier(char str, va_list args);
void	put_and_substract(int *n, char c);
void	print_c(void);
void	print_d(void);
void	print_d_right(void);
void	print_d_left(void);
void	print_d0(void);
void	print_d0_right(void);
void	print_u(void);
void	print_u_right(void);
void	print_u_left(void);
void	print_x(void);
void	print_x_right(void);
void	print_x_left(void);
void	print_p(void);
void	print_p_right(unsigned long up, int newlen);
void	print_p_left(unsigned long up, int newlen);
void	print_p_null(void);
void	print_s_null(void);
void	print_s(void);
#endif

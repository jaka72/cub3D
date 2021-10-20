/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 13:57:25 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/10 13:57:25 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_ischar(int c);
int		ft_isalnum_hex(char c);
int		ft_make_hex(char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_ispath(int c);

#endif

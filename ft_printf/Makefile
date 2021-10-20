# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/16 14:48:49 by jmurovec      #+#    #+#                  #
#    Updated: 2021/02/16 14:48:49 by jmurovec      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
MAN_FILES		= 	ft_printf.o\
					libft/ft_isdigit.o\
					libft/ft_putchar.o\
					libft/ft_putnbr.o\
					libft/ft_putnbr_long.o\
					libft/ft_putnbr_hex.o\
					libft/ft_strlen.o\
					libft/ft_getlen.o\
					libft/ft_getlen_hex.o\
					libft/ft_putstr.o\
					libft/ft_putstr_precision.o\
					libft/ft_put_and_substract.o\
					sources/check_flags.o\
					sources/find_specifier.o\
					sources/print_c.o\
					sources/print_d.o\
					sources/print_d_right.o\
					sources/print_d_left.o\
					sources/print_d0.o\
					sources/print_d0_right.o\
					sources/print_u.o\
					sources/print_u_right.o\
					sources/print_u_left.o\
					sources/print_x.o\
					sources/print_x_right.o\
					sources/print_x_left.o\
					sources/print_p.o\
					sources/print_s_null.o\
					sources/print_s.o

HEADER_FILES	=	ft_printf.h
CFLAGS			=	-Wall -Wextra -Werror

OBJ_FILES = $(MAN_FILES)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rcs $(NAME) $(OBJ_FILES)

%.o:		%.c $(HEADER_FILES)
			gcc -c $(CFLAGS) -o $@ $<

clean:
			rm -f $(MAN_FILES)

fclean: clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re

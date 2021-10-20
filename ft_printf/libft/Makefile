# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmurovec <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/14 18:03:05 by jmurovec      #+#    #+#                  #
#    Updated: 2021/02/14 18:03:05 by jmurovec      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
MAN_FILES		= ft_isdigit.o ft_strlen.o ft_putchar.o ft_putnbr.o ft_putnbr_long.o \
				ft_putnbr_hex.o ft_getlen.o ft_getlen_hex.o ft_putstr_precision.o \
				ft_put_and_substract.o ft_putstr.o

HEADER_FILES	=	libft.h
CFLAGS			=	-Wall -Wextra -Werror

OBJ_FILES = $(MAN_FILES)

all:		$(NAME)

$(NAME):	$(OBJ_FILES)
			ar -rcs $(NAME) $(OBJ_FILES)

%.o: 		%.c $(HEADER_FILES)
			gcc -c $(CFLAGS) -o $@ $<

clean:
			rm -f $(MAN_FILES)

fclean: clean
			rm -f $(NAME)

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY: 	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:31:20 by cduffaut          #+#    #+#              #
#    Updated: 2023/11/03 22:42:55 by csil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf.a

SRCS	= ft_printf.c print_c_s.c print_hexa.c print_i_d.c print_p.c print_u.c

OBJS	= $(SRCS:%.c=%.o)

GCC	= gcc -Wall -Wextra -Werror

.c.o: $(GCC) -c $> -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) ft_printf.o print_c_s.o print_hexa.o print_i_d.o print_p.o print_u.o
	ranlib $(NAME)

clean:
	rm -f ft_printf.o print_c_s.o print_hexa.o print_i_d.o print_p.o print_u.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY : re fclean clean all

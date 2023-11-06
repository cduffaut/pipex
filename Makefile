# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csil <csil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 22:34:48 by csil              #+#    #+#              #
#    Updated: 2023/11/05 20:48:21 by csil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= \
		pipex.c child_process.c parent_process.c handle_error.c \
		execute_cmd.c

LIBFT		=		./libft/libft.a

FT_PRINTF	=		./ft_printf/ft_printf.a

MLIBFT		=		@$(MAKE) -C libft

MFT_PRINTF	=		@$(MAKE) -C ft_printf

OBJS	= $(SRCS:.c=.o)

GCC	= gcc -Wall -Wextra -Werror

NAME	= pipex

all:	lib $(NAME)

lib:
	$(MLIBFT) all
	$(MFT_PRINTF) all

%.o:	%.c ./libft/libft.h Makefile ./ft_printf/ft_printf.h Makefile
	$(GCC) -c $< -o $@

$(NAME) :	${OBJS}
		$(GCC) -o ${NAME} ${OBJS} ${LIBFT} ${FT_PRINTF}

clean:
	rm -f $(OBJS)
	${MLIBFT} clean
	${MFT_PRINTF} clean

fclean:	clean
	rm -f $(NAME)
	${MLIBFT} fclean
	${MFT_PRINTF} fclean

re:	fclean all

.PHONY : re fclean clean all bonus

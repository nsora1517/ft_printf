# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 01:03:40 by snagasak          #+#    #+#              #
#    Updated: 2026/06/03 01:31:01 by snagasak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


CC = cc
CFLAGS = -Wall -Werror -Wextra
PF_CMD = ar rcs
RM = rm -f
HEADER = ft_printf.h

SRC = ft_printf.c\
      ft_putchar_p.c\
	  ft_puthex_p.c\
	  ft_putnbr_p.c\
	  ft_putptr_p.c\
	  ft_putstr_p.c\
	  ft_putunsigned_p.c

OBJS = $(SRC:.c=.o)

all:${NAME}
${NAME}:${OBJS}
	${PF_CMD} ${NAME} ${OBJS}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

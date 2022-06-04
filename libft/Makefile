# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 18:46:17 by bde-biol          #+#    #+#              #
#    Updated: 2022/06/04 18:46:18 by bde-biol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_putchar_fd.c ft_strlen.c ft_putstr_fd.c \
	ft_putnbr_fd.c ft_isdigit.c ft_atoi.c

OBJS	= ${SRCS:.c=.o}
CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
NAME	= libft.a

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

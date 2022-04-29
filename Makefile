# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:38:32 by bde-biol          #+#    #+#              #
#    Updated: 2022/04/26 07:17:44 by bde-biol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRCS = ${addprefix libft/,ft_putchar_fd.c ft_strlen.c ft_putstr_fd.c ft_putnbr_fd.c)
LIBFT_OBJS = $LIBFT_SRCS:.c=.o}
SRCS = ft_printf.c
OBJS = $LIBFT_SRCS:.c=.o}


CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
LIBFT_NAME	= libft.a
NAME	= libftprintf.a


all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# ${NAME}:	${OBJS} ${LIBFT_NAME}
# 			${AR} ${NAME} ${OBJS} ${LIBFT_NAME}

# ${LIBFT_NAME}:	${LIBFT_OBJS}
# 				${AR} ${LIBFT_NAME} ${LIBFT_OBJS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


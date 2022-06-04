# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:38:32 by bde-biol          #+#    #+#              #
#    Updated: 2022/06/04 19:58:03 by bde-biol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c
OBJS = ${SRCS:.c=.o}

LIBFT = libft


CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs --thin
NAME	= libftprintf.a
LIBFT_NAME	= libft/libft.a


all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -I includes/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@make -C $(LIBFT)
			${AR} ${NAME} ${OBJS} ${LIBFT_NAME}

bonus		: all

main:	${NAME} main.c
		${CC} ${CFLAGS} -I includes/ -o main main.c ${NAME} ${LIBFT_NAME}

clean:
			@make clean -C $(LIBFT)
			${RM} ${OBJS} ${LIBFT_OBJS} ${BONUS_OBJS}

fclean:		clean
			@make fclean -C $(LIBFT)
			${RM} ${NAME} ${LIBFT_NAME}

re:			fclean all

.PHONY:		all clean fclean re


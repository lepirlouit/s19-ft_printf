# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 19:38:32 by bde-biol          #+#    #+#              #
#    Updated: 2022/06/05 17:08:06 by bde-biol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_eval_format_flags.c ft_padding.c ft_min_max.c \
	ft_number_utils.c ft_put.c ft_print_alpha.c ft_print_numbers.c
OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft/

CC	= gcc
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
NAME	= libftprintf.a
LIBFT	= $(LIBFT_DIR)libft.a
LNK  = -L $(LIBFT_DIR) -lft


all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -I includes/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LIBFT}
			cp ${LIBFT} $(NAME)
			${AR} ${NAME} ${OBJS}

${LIBFT}:
			make -C $(LIBFT_DIR)

bonus		: all

main:	${NAME} main.c
		${CC} ${CFLAGS} -I includes/ -o main main.c ${LNK} ${NAME}

clean:
			@make -C $(LIBFT_DIR) clean
			${RM} ${OBJS}

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


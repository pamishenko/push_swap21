# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 21:35:39 by ttanja            #+#    #+#              #
#    Updated: 2021/09/10 23:17:45 by ttanja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= push_swap

HEADERS_FOLDER	= header/

SRC    = \
		./src/ft_atoi.c \
		./src/ft_base_utils.c \
		./src/ft_calloc.c \
		./src/ft_double_checker.c \
		./src/ft_is_sorted.c \
		./src/ft_memcpy.c \
		./src/ft_print_stack.c \
		./src/ft_push_swap.c \
		./src/ft_push.c \
		./src/ft_putnbr_fd.c \
		./src/ft_putstr_fd.c \
		./src/ft_reverse.c \
		./src/ft_rotate.c \
		./src/ft_sort_max_element.c \
		./src/ft_sort.c \
		./src/ft_strlen.c  \
		./src/ft_swap.c \
		./src/ft_utils_instruction.c \
		./src/ft_utils_push.c \
		./src/ft_utils_stack_init.c \
		./src/ft_utils.c
	
SRCS_OBJS	= ${SRC:.c=.o}
DEPS		= ${SRC:.c=.d}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I ${HEADERS_FOLDER} -MMD -MP

RM			= rm -f

all:		
			make ${NAME}

-include $(DEPS)

${NAME}:	${SRCS_OBJS}	
			${CC} ${CFLAGS} ${SRCS_OBJS} -o ${NAME}

debug:		
		gcc -g -Wall -Wextra -Werror -I header/ src/*.c -o push_swap
clean:
			${RM} ${SRCS_OBJS}
			${RM} ${DEPS}

fclean: 	clean
			${RM} ${NAME}

re:         fclean all

.PHONY:        all clean fclean re

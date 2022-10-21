# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2022/10/21 11:10:27 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
HEADER := -I./
OBJS:= small_stack.o swap_instructions.o swap_utils_combinations.o swap_utils.o swap_utils2.o big_stack.o input_handler.o input_aux.o
OBJS_T := tester.o
CC := gcc
CFLAGS :=-Wall -Wextra -Werror
LIBPATHS := -L./ -lftprintf
RM := rm -f

all:linux

$(NAME): ${OBJS}
	$(CC) $(OBJS) -o $(NAME)

linux: $(OBJS)
	${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${LIBPATHS} ${HEADER} -o ${NAME}

test:${OBJS} libft.a
	${CC} ${CFLAGS} tester.c ${OBJS} ${HEADER} ${LIBPATHS} -o tester

libft.a:
	${MAKE} -C ../libft/ all
	mv ../libft/libft.a ./

clean:
	${RM} *.o
	${RM} tester

fclean: clean
	${RM} push_swap

re: fclean all

 .PHONY:linux test
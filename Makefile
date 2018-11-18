# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 16:58:35 by ibouroum          #+#    #+#              #
#    Updated: 2018/11/17 16:58:37 by ibouroum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = fillit
all : $(NAME)

$(NAME) : *.c
	gcc $(FLAGS) -c *.c libft/*.c
	rm -f main.o
	gcc $(FLAGS) main.c *.o -o $@
clean :
	rm -f *.o
fclean : clean
	rm -f fillit
re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 13:17:46 by tmlkshk           #+#    #+#              #
#    Updated: 2019/09/29 15:53:57 by tmlkshk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./src/*.c
OBJ = ./src/*.o
FLAG = -Wall -Wextra -Werror

LIBFT = src/libft/
all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAG) -o $(NAME) $(SRC) -L $(LIBFT) -lft

clean:
		rm -f $(OBJ)
		make -C $(LIBFT) clean
fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean
re: fclean all
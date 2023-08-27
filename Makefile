# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 01:37:23 by rimouarrak        #+#    #+#              #
#    Updated: 2023/08/27 19:32:30 by rimouarrak       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = parsing.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c utils_pars.c\
		element_check.c utils_gnrl.c

NAME = nanort
LIBFT = libft.a
LIBFT_DIR = libft/

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		cc -fsanitize=address $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .

clean:
		rm -rf $ libft.a
		rm -rf $(OBJS)
		rm -rf $(BOBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re
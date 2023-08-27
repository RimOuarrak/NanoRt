# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 14:04:46 by rouarrak          #+#    #+#              #
#    Updated: 2022/10/20 22:31:00 by rouarrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_isdigit.c ft_putchar_fd.c ft_strlcpy.c ft_tolower.c \
		ft_atoi.c ft_isprint.c ft_putendl_fd.c ft_strlen.c ft_toupper.c \
		ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strncmp.c ft_split.c\
		ft_calloc.c ft_memcmp.c ft_strchr.c ft_strnstr.c ft_striteri.c\
		ft_isalnum.c ft_memcpy.c ft_strdup.c ft_strrchr.c ft_strtrim.c\
		ft_isalpha.c ft_memmove.c ft_strjoin.c ft_substr.c ft_strmapi.c\
		ft_isascii.c ft_memset.c ft_strlcat.c ft_putnbr_fd.c ft_itoa.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c

OBJS = ${SRCS:.c=.o}

BOBJS = ${OBJS} ${BSRCS:.c=.o}

NAME = libft.a

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

bonus: ${BOBJS}
	ar rcs ${NAME} ${BOBJS}

all: ${NAME}
	
${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}
	rm -f ${BOBJS}

fclean: clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 20:15:57 by vgrenier          #+#    #+#              #
#    Updated: 2016/06/20 18:21:31 by vgrenier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_itoa.c \
ft_memccpy.c \
ft_putchar_fd.c \
ft_strcat.c \
ft_striter.c \
ft_strncmp.c \
ft_strsub.c \
ft_atoi.c \
ft_lstadd.c \
ft_memchr.c \
ft_putendl.c \
ft_strchr.c \
ft_striteri.c \
ft_strncpy.c \
ft_strtrim.c \
ft_bzero.c \
ft_lstdel.c \
ft_memcmp.c \
ft_putendl_fd.c \
ft_strclr.c \
ft_strjoin.c \
ft_strnequ.c \
ft_tolower.c \
ft_isalnum.c \
ft_lstdelone.c \
ft_memcpy.c \
ft_putnbr.c \
ft_strcmp.c \
ft_strlcat.c \
ft_strnew.c \
ft_toupper.c \
ft_isalpha.c \
ft_lstiter.c \
ft_memdel.c \
ft_putnbr_fd.c \
ft_strcpy.c \
ft_strlen.c \
ft_strnstr.c \
ft_isascii.c \
ft_lstmap.c \
ft_memmove.c \
ft_putstr.c \
ft_strdel.c \
ft_strmap.c \
ft_strrchr.c \
ft_isdigit.c \
ft_lstnew.c \
ft_memset.c \
ft_putstr_fd.c \
ft_strdup.c \
ft_strmapi.c \
ft_strsplit.c \
ft_isprint.c \
ft_memalloc.c \
ft_putchar.c \
ft_realloc.c \
ft_strequ.c \
ft_strncat.c \
ft_strstr.c \
ft_strrevchr.c \
get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) ; ar rc $(NAME) $(OBJ) ; ranlib $(NAME)

test: all
	gcc -Wall -Werror -Wextra main.c -L. -lft

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

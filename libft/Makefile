# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 15:47:29 by tberube-          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/01/17 10:41:07 by tberube-         ###   ########.fr        #
=======
#    Updated: 2021/11/03 15:16:20 by tberube-         ###   ########.fr        #
>>>>>>> f20a70b6ee8cb7e79360fd098288e1ae432eff17
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS_S = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS = ${SRCS:.c=.o}
BONUS_O = $(BONUS_S:.c=.o)

.c.o:
	${CC} $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus:		$(NAME) $(BONUS_O)
	ar rcs $(NAME) $(BONUS_O)
clean:
	/bin/rm -f $(OBJS) $(BONUS_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

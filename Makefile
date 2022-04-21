# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 14:17:42 by tberube-          #+#    #+#              #
#    Updated: 2022/04/13 17:14:09 by tberube-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = gcc
HEADER = so_long.h

NAME = so_long
SRCS = check_grid.c events.c invalide_map.c map_check.c \
		mapping.c put_img_on_map.c so_long.c dupMap.c load_textures.c
		
GET_NEXT_LINE = get_next_line.c get_next_line_utils.c 
GNL_HEADER = ./GNL/get_next_line.h
GNL_PATH = ./GNL/

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

GNL_SRCS = $(addprefix $(GNL_PATH), $(GET_NEXT_LINE))

LIBFT_PATH = ./libft

OBJS = ${SRCS:.c=.o} 
GNL_OBJS = ${GNL_SRCS:.c=.o}

.c.o:
	${CC} $(CFLAGS) -I$(GNL_HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(MLX_FLAGS) $(LIBFT_PATH)/libft.a -o $(NAME)
	

all: $(NAME)

debug: CFLAGS += -g
debug: $(NAME)

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	@make clean -C $(LIBFT_PATH) $(GET_NEXT_LINE_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongwpa <jeongwpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 20:13:16 by jeongwpa          #+#    #+#              #
#    Updated: 2024/06/27 20:14:51 by jeongwpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs
INC_DIR = includes

SRC = minirt.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)
NAME = minirt
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INC_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

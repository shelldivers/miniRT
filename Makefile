# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongwpa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 18:05:55 by jeongwpa          #+#    #+#              #
#    Updated: 2024/08/01 18:05:55 by jeongwpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MINIRT = minirt.c minirt_utils.c
SRC_RAY = color.c ray.c
SRC_SPAHE = cylinder.c hittable.c plane.c sphere.c
SRC_VEC3 = vec3.c vec3_utils.c
SRC_UTILS = camera.c error.c key_hook.c

SRC_ALL = $(addprefix ray/, $(SRC_RAY))
SRC_ALL += $(addprefix shape/, $(SRC_SPAHE))
SRC_ALL += $(addprefix vec3/, $(SRC_VEC3))
SRC_ALL += $(SRC_UTILS)

SRCS += $(addprefix src/, $(SRC_ALL))

SRCS += $(SRC_MINIRT)

OBJS = $(SRC_ALL:.c=.o)

NAME = minirt
CC = cc
FLAG = -Wall -Wextra -Werror

LIB_FT = libft/libft.a
LIB_MLX = mlx/libmlx.dylib

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@make -C libft
	@make -C mlx
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(LIB_FT) $(LIB_MLX) -framework OpenGL -framework AppKit
	@echo "minirt is created"

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@make clean -C libft
	@make clean -C mlx

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all

.PHONY : all clean fclean re

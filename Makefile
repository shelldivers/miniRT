# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwojung <jiwojung@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 18:05:55 by jeongwpa          #+#    #+#              #
#    Updated: 2024/08/27 20:15:30 by jiwojung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_MANDATORY = main.c srcs/shape/cone_endcaps.c srcs/shape/cylinder_surface.c srcs/shape/texture.c srcs/shape/cone_surface.c srcs/shape/hittable.c srcs/shape/cone.c srcs/shape/cylinder.c srcs/shape/bump.c srcs/shape/sphere.c srcs/shape/hittable_utils.c srcs/shape/plane.c srcs/shape/cylinder_endcaps.c srcs/minirt_color.c srcs/parse/minirt_parse_utils.c srcs/parse/minirt_parse_vec3.c srcs/parse/minirt_parse_utils3.c srcs/parse/minirt_parse_shape.c srcs/parse/minirt_parse.c srcs/parse/minirt_parse_texture2.c srcs/parse/minirt_parse_utils2.c srcs/parse/minirt_parse_world.c srcs/parse/minirt_parse_texture.c srcs/parse/minirt_parse_scene.c srcs/minirt.c srcs/image.c srcs/vec/vec3.c srcs/vec/vec3_utils.c srcs/vec/vec2.c srcs/error.c srcs/minirt_async.c srcs/mlx_hook/key_hook.c srcs/mlx_hook/loop_hook.c srcs/light_lst_utils.c srcs/ray/ray.c srcs/ray/color.c srcs/reflection/reflection.c srcs/reflection/reflection_utils.c 
SRCS_BONUS = main_bonus.c srcs/minirt_bonus.c srcs/shape/plane_bonus.c srcs/shape/cylinder_endcaps_bonus.c srcs/shape/sphere_bonus.c srcs/shape/cone_bonus.c srcs/shape/cylinder_bonus.c srcs/shape/hittable_utils_bonus.c srcs/shape/cone_surface_bonus.c srcs/shape/bump_bonus.c srcs/shape/cone_endcaps_bonus.c srcs/shape/cylinder_surface_bonus.c srcs/shape/hittable_bonus.c srcs/shape/texture_bonus.c srcs/error_bonus.c srcs/minirt_color_bonus.c srcs/image_bonus.c srcs/parse/minirt_parse_shape_bonus.c srcs/parse/minirt_parse_texture2_bonus.c srcs/parse/minirt_parse_utils_bonus.c srcs/parse/minirt_parse_bonus.c srcs/parse/minirt_parse_scene_bonus.c srcs/parse/minirt_parse_vec3_bonus.c srcs/parse/minirt_parse_world_bonus.c srcs/parse/minirt_parse_utils2_bonus.c srcs/parse/minirt_parse_utils3_bonus.c srcs/parse/minirt_parse_texture_bonus.c srcs/light_lst_utils_bonus.c srcs/minirt_async_bonus.c srcs/vec/vec3_bonus.c srcs/vec/vec3_utils_bonus.c srcs/vec/vec2_bonus.c srcs/mlx_hook/key_hook_bonus.c srcs/mlx_hook/loop_hook_bonus.c srcs/ray/ray_bonus.c srcs/ray/color_bonus.c srcs/reflection/reflection_utils_bonus.c srcs/reflection/reflection_bonus.c 
SRCS_MANDATORY := $(addprefix mandatory/, $(SRCS_MANDATORY))
SRCS_BONUS := $(addprefix bonus/, $(SRCS_BONUS))

INCLUDES = includes includes/shape

INCLUDES_MANDATORY = $(addprefix mandatory/, $(INCLUDES))
INCLUDES_MANDATORY += mlx libft/includes
INCLUDES_MANDATORY := $(addprefix -I, $(INCLUDES_MANDATORY))

INCLUDES_BONUS = $(addprefix bonus/, $(INCLUDES))
INCLUDES_BONUS += mlx libft/includes
INCLUDES_BONUS := $(addprefix -I, $(INCLUDES_BONUS))

OBJS_MANDATORY = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
	SRCS = $(SRCS_BONUS)
	OBJS = $(OBJS_BONUS)
else
	SRCS = $(SRCS_MANDATORY)
	OBJS = $(OBJS_MANDATORY)
endif

LIB_FT = libft/libft.a

NAME = minirt
CC = cc
FLAG = -Wall -Wextra -Werror

ifdef PRE_PROCESSING
	FLAG += -DPRE_PROCESSING=0
else
	FLAG += -DPRE_PROCESSING=1
endif

all : $(NAME)

bonus : $(NAME)
	@make BONUS=1

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@make -C libft
	@make -C mlx
	@cp mlx/libmlx.dylib .
	$(CC) $(FLAG) -o $(NAME) $(OBJS) $(LIB_FT) $(INCLUDES_MANDATORY) -framework OpenGL -framework AppKit -lmlx -Lmlx
	@echo "minirt is created"

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@ $(INCLUDES_MANDATORY) $(INCLUDES_BONUS)

clean :
	@rm -f $(OBJS_MANDATORY) $(OBJS_BONUS)
	@make clean -C libft
	@make clean -C mlx

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft
	@rm -f libmlx.dylib

re : fclean all

re_preprocessing : $(NAME)
	@rm -f $(NAME) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@make

re_realtime : $(NAME)
	@rm -f $(NAME) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@make PRE_PROCESSING=1

.PHONY : all clean fclean re

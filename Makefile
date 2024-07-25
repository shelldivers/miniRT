#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

NAME = miniRT

S_INCLUDES = includes/
B_INCLUDES = includes_bonus/
LIBFT_INCLUDES = libft/includes
MLX_INCLUDES = minilibx/

SOURCES = srcs/


B_SOURCES = srcs_bonus/


CC = cc
CFLAGS = #-Wall -Wextra -Werror
LIBFT_FLAGS = -I$(LIBFT_INCLUDES) -I$(MLX_INCLUDES) -Llibft -lft 
MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit 
RM = rm -rf

M_FILES += vec3.c vec3_calc.c ray.c point3.c color.c sphere.c plane.c cylinder.c
#M_FILES += $(addprefix $(S_PARSE), $(PARSER))

B_FILES += minirt_bonus.c
#B_FILES += $(addprefix $(B_PARSE), $(BS_PARSER))

S_SRCS = $(addprefix $(SOURCES), $(M_FILES))
S_OBJS = $(S_SRCS:.c=.o)
B_SRCS = $(addprefix $(B_SOURCES), $(B_FILES))
B_OBJS = $(B_SRCS:.c=.o)

ifdef objs
	SRCS = $(B_SRCS)
	OBJS = $(B_OBJS)
	INCLUDES = $(B_INCLUDES)
else
	SRCS = $(S_SRCS)
	OBJS = $(S_OBJS)
	INCLUDES = $(S_INCLUDES)
endif

S_SRCS += minirt.c

all: $(NAME) $(HEADER)

$(NAME): $(OBJS)
	@make -C ./minilibx
	@cp ./minilibx/libmlx.dylib .
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I$(INCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS)

bonus: 
	@make objs=1 all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -Imlx -I$(INCLUDES) -I$(LIBFT_INCLUDES)

clean:
#	@make clean -C ./minilibx
#	@make clean -C ./libft
	@$(RM) $(S_OBJS) $(B_OBJS)

fclean: clean
#	@make fclean -C ./libft
#	@$(RM) libmlx.dylib
	@$(RM) $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all bonus clean fclean re
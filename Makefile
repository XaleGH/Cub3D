NAME = cub3d
DIR_SRC = src/
DIR_OBJ = obj/
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g -ggdb -O3 -ffast-math -Imlx_linux -fPIE
LDFLAGS = -lreadline -lm
RM = rm -f

SRCS =  $(wildcard $(DIR_SRC)*.c) \
		$(wildcard $(DIR_SRC)/utils/*.c) \
		$(wildcard $(DIR_SRC)/parsing/*.c) \
		$(wildcard $(DIR_SRC)/raycasting/*.c) \
		$(wildcard $(DIR_SRC)/player/*.c)

OBJS = $(SRCS:$(DIR_SRC)%.c=$(DIR_OBJ)%.o)


# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m



all: $(NAME)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(BOLD)$(BLUE)------------------------------------------$(RESET)"
	@echo "$(BOLD)$(RED)🛠️ 🚧        Compilation started       🚧🛠️$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(ORANGE)⏳      Compilation in progress...      ⏳$(RESET)"
	@make -sC ./libft
	@make -sC ./mlx
	@echo "\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -lXext -lX11
	@echo "$(BOLD)$(GREEN)🎆           Compilation clear          🎆$(RESET)"
	@echo "$(BOLD)$(BLUE)------------------------------------------$(RESET)"

clean:
	@make clean -sC libft
	@make clean -sC mlx
	@rm -rf $(DIR_OBJ)
	@echo "$(BOLD)$(YELLOW)🧹🧼     Cleaned .o Cub3d's files     🧼🧹$(RESET)"
	@echo "\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "$(BOLD)$(YELLOW)🧹🧼        Cleaned Cub3d exec        🧼🧹$(RESET)"
	@echo "\n"

re: fclean all
NAME			=		so_long

CC				=		cc

CFLAGS			=		-Wall -Wextra -Werror
INCLUDE			=		-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

LIBFT_DIR		=		libft
LIBFT_A			=		libft/libft.a

MLX_DIR			=		mlx

SRCS			=		./srcs/map/gnl/get_next_line.c			\
						./srcs/map/flood_fill.c					\
						./srcs/map/gnl/get_next_line_utils.c	\
						./srcs/map/enemy.c						\
						./srcs/map/map_checker_utils.c			\
						./srcs/map/map_checker.c				\
						./srcs/map/map_reader.c					\
						./srcs/map/tilemap.c					\
						./srcs/map/ft_strlen_int.c				\
						./srcs/game/draw_wall.c					\
						./srcs/game/end_player.c				\
						./srcs/game/end_program.c				\
						./srcs/game/enemy_movement.c			\
						./srcs/game/error.c						\
						./srcs/game/follow_enemy_movement.c		\
						./srcs/game/game_init.c					\
						./srcs/game/input.c						\
						./srcs/game/open_imgs.c					\
						./srcs/game/open_panel.c				\
						./srcs/game/open_wall_imgs.c			\
						./srcs/game/player_movement.c			\
						./srcs/game/render.c					\
						./srcs/game/reset.c						\
						./srcs/game/update.c					\
						./srcs/main.c

OBJ_DIR			=		./srcs/obj

OBJ_FILES		=		$(SRCS:.c=.o)

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) Game -" $(NONE)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(LDFLAGS) $(LIBFT_A) $(INCLUDE)  $^ -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJ_FILES)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re	:
	@make -C $(LIBFT_DIR)
	@make fclean
	@make all

.PHONY: all make clean fclean re

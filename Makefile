NAME			=		so_long

CC				=		cc

CFLAGS			=		-Wall -Wextra -Werror
INCLUDE			=		-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

LIBFT_DIR		=		libft
LIBFT_A			=		libft/libft.a

MLX_DIR			=		mlx

SRCS_MAN		=		./srcs/map/gnl/get_next_line.c						\
						./srcs/map/flood_fill.c								\
						./srcs/map/gnl/get_next_line_utils.c				\
						./srcs/map/enemy.c									\
						./srcs/map/map_checker_utils.c						\
						./srcs/map/map_checker.c							\
						./srcs/map/map_reader.c								\
						./srcs/map/tilemap.c								\
						./srcs/game/draw_wall.c								\
						./srcs/game/end_player.c							\
						./srcs/game/end_program.c							\
						./srcs/game/enemy_movement.c						\
						./srcs/game/error.c									\
						./srcs/game/follow_enemy_movement.c					\
						./srcs/game/game_init.c								\
						./srcs/game/input.c									\
						./srcs/game/open_imgs.c								\
						./srcs/game/open_panel.c							\
						./srcs/game/open_wall_imgs.c						\
						./srcs/game/player_movement.c						\
						./srcs/game/render.c								\
						./srcs/game/reset.c									\
						./srcs/game/update.c								\
						./srcs/main.c
OBJS_MAND		=	$(SRCS_MAN:.c=.o)

SRCS_BONUS		=		./srcs_bonus/map/gnl/get_next_line_bonus.c			\
						./srcs_bonus/map/flood_fill_bonus.c					\
						./srcs_bonus/map/gnl/get_next_line_utils_bonus.c	\
						./srcs_bonus/map/enemy_bonus.c						\
						./srcs_bonus/map/map_checker_utils_bonus.c			\
						./srcs_bonus/map/map_checker_bonus.c				\
						./srcs_bonus/map/map_reader_bonus.c					\
						./srcs_bonus/map/tilemap_bonus.c					\
						./srcs_bonus/game/draw_wall_bonus.c					\
						./srcs_bonus/game/end_player_bonus.c				\
						./srcs_bonus/game/end_program_bonus.c				\
						./srcs_bonus/game/enemy_movement_bonus.c			\
						./srcs_bonus/game/error_bonus.c						\
						./srcs_bonus/game/follow_enemy_movement_bonus.c		\
						./srcs_bonus/game/game_init_bonus.c					\
						./srcs_bonus/game/input_bonus.c						\
						./srcs_bonus/game/open_imgs_bonus.c					\
						./srcs_bonus/game/open_panel_bonus.c				\
						./srcs_bonus/game/open_wall_imgs_bonus.c			\
						./srcs_bonus/game/player_movement_bonus.c			\
						./srcs_bonus/game/render_bonus.c					\
						./srcs_bonus/game/reset_bonus.c						\
						./srcs_bonus/game/update_bonus.c					\
						./srcs_bonus/main_bonus.c
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

ifdef FLAG
	OBJS_FILES = $(OBJS_BONUS)
else
	OBJS_FILES = $(OBJS_MAND)
endif

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
PURPLE='\033[35m'
BLUE='\033[34m'
DELETELINE='\033[K;

all : $(NAME)

bonus :
	make all FLAG=1

$(NAME) : $(OBJS_FILES)
	@echo $(CURSIVE)$(YELLOW) "      - Making $(NAME) Game -" $(NONE)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_A) $(INCLUDE)  $^ -o $@
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(CURSIVE)$(YELLOW) "        - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN) "            - Complete -"$(NONE)

%.o : %.c
	@echo $(CURSIVE)$(YELLOW) "      - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJS_MAND) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(BLUE) "     - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo $(CURSIVE)$(PURPLE)"      - clean $(NAME) file -"$(NONE)

re	:
	@make -C $(LIBFT_DIR)
	@make fclean
	@make all

.PHONY: all make clean fclean bonus re

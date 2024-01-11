NAME			=		so_long
CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror
INCLUDE			=		-lmlx -framework OpenGL -framework AppKit
SRCS_DIR		=		$(SRC_GNL) $(SRC_MAP) $(SRC_GAME)

SRC_GNL			=		./srcs/map/gnl/get_next_line.c			\
						./srcs/map/gnl/get_next_line_utils.c

SRC_MAP			=		./srcs/map/enemy.c						\
						./srcs/map/map_checker_utils.c			\
						./srcs/map/map_checker.c				\
						./srcs/map/map_reader.c					\
						./srcs/map/tilemap.c

SRC_GAME		=		./srcs/game/draw_wall.c					\
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
						./srcs/game/update.c

OBJ_DIR			=		./srcs/obj

SRC_FILES		=		$(SRCS_DIR)

OBJ_FILES		=		$(SRCS_DIR:.c=.o)

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
	@echo $(CURSIVE)$(YELLOW) "- Making $(NAME) Game -" $(NONE)
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo $(CURSIVE)$(YELLOW) " - Compiling $(NAME) -" $(NONE)
	@echo $(GREEN)"        - Complete -"$(NONE)

$(OBJ) : $(SRCS_DIR)
	@echo $(CURSIVE)$(YELLOW) "  - Making object files -" $(NONE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJ_FILES)
	@echo $(CURSIVE)$(BLUE) "   - clean OBJ files -" $(NONE)

fclean : clean
	@rm -fr $(NAME)
	@echo $(CURSIVE)$(PURPLE)"  - clean $(NAME) file -"$(NONE)

re	:
	@make fclean
	@make all

.PHONY: all make clean fclean re

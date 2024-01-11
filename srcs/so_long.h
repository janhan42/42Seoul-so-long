/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:23:37 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 13:12:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* 스프라이트 사이즈 */
# define IMG_SIZE 64
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* 간편 구조체 enum */

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_color
{
	int r;
	int g;
	int b;
	int a;
}	t_color;

// ----------- 맵 타일

typedef enum s_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;

/* 각 타일의 인포메이션 */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type; // 시작 타일
	t_vector		position; // POSITION
	struct s_tile	*up;	// 주변 타일
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}	t_mapcheckerdata;


// ----------- 이미지

/* 벽 이미지 */
typedef struct	s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

/* 수집 이미지 */
typedef struct s_collect_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

/* 이펙트 조정 */
typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

/* 이펙트 페널 */
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

// ----------- 적 인포

/* 적 타입 인포 */
typedef enum s_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
	FOLLOW_ENEM = 'F'
}	t_enemytype;

/* 적 애니메이션 인포 */
typedef struct s_enemy_img
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;
	int		follow_anim;
	void	*follow_current;
	void	*follow_01;
	void	*follow_02;
}	t_enemy_img;

/* 적 링크드 리스트 */
typedef struct s_enemy
{
	t_enemytype			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct	s_enemy		*next;
}	t_enemy;

// ----------- 플레이어 인포
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;


/* 키입력 */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

// ----------- 중요 게임 구조체

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		window_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel; // 사망시 화면 반짝임
	void			*white_panel; // 탈출시 화면 반짝임
}	t_game;


// -------------------- 함수

/* get_next_line */
int		get_next_line(int fd, char **line);
int		ft_end_of_read(int readcount, char **readbuff, char **line);
int		validparmas(int fd, char **lien, char **readbuff);
int		ft_linelen(char *line);
int		ft_newread(int fd, char **oldread);
char	*ft_getline(int	len, char *read);
char	*ft_clearline(int len, char *read);

/* game */
t_bool	start(t_game *game, int ac, char **av);
t_tile	**map_init(int ac, char **av, t_game *gmae);
void	open_imgs(t_game *game);
void	open_wallimgs_down(t_game *game);
void	open_wallimgs_up(t_game *game);
void	*new_panel(t_game *game, t_color color);
void	color_panel(t_panel *panel, t_color color);
t_color	new_color(int r, int g, int b, int a);

/* map */
int		valid_map(char **map);
int 	valid_file(int ac, char *file);
char	**read_map(char *file);
int		valid_char(char c);
int		valid_uniquechar(char c, char checker, t_bool *state);
int		valid_border(char c, t_vector point, t_vector size);

// generate //
t_tile	**generate_tilemap(char **map, t_game *game);

/* enemy && movement */
void	add_enemy(t_game *game, t_enemytype type, t_tile *tile);
void	move_enemies(t_game *game);
t_bool	move_ver(t_enemy *enemy, t_game *game);
t_bool	move_hor(t_enemy *enemy, t_game *game);
void	move_enemy_to(t_enemy *enemy, t_tile *tile);
t_bool	change_dir(t_enemy *enemy);
void	follow_player(t_enemy *enemy, t_game *game);
int		define_dir(int value);

/* player movement && input */
void	effect_anim(t_effect *effect, t_vector pos);
void	action_anim(t_player *player);
t_bool	move_to(t_game *game, t_tile *tile);
int		input(int key, t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	pick_collect(t_game* game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

/* draw */
void	draw_wall(t_tile tile, t_game game, t_vector pos);
void	render(t_game game);
int		update(t_game *game);
/* error */
int		error(char *message);
void	print_warnig(char *message);
void	*null_error(char *message);

/* game end or reset */
int		end_program(t_game *game);
int		reset(t_game *game);
void	kill_player(t_game *game, t_vector pos);
void	remove_player(t_game *game);
#endif

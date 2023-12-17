/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:27:00 by janhan            #+#    #+#             */
/*   Updated: 2023/12/17 16:49:58 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

/* ========== define ===========*/
# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define BUFFER_SIZE 9999

typedef struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*background;
}	t_img;

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		item;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}	t_data;
/*========= gnl utils ==========*/
char	*ft_strndup_gnl(char *input, int n);
char	*ft_strnjoin_gnl(char *s1, char *s2, int n);
void	ft_free_gnl(char **p);
int		ft_strlen_gnl(char *s);
int		ft_strchr_gnl(char *s, int c, int flag);
char	*get_next_line(int fd);
/*========= key hook ==========*/
void	ft_move(t_data *data, char pos, int dir);
void	ft_win(t_data *data);
int	ft_key_hook(int	keycode, t_data *data);
/*========= map func ==========*/
int		ft_line_length(int fd);
int		ft_count_lines(int fd, int x, int img_w);
void	ft_create_map(t_data *data);
int	ft_count_c(char *s, char c);
void	ft_parse_input(t_data *data, char **argv, int argc);
/*========= put img ===========*/
void	ft_put_background(t_data *data);
void	ft_put_object(t_data *data, char *relative_paht);
void	ft_put_player(t_data *data);
/*========= so_long ============*/
int	ft_exit(t_data *data);
/*========= init func ==========*/
void	ft_init(t_data *data, t_map *map);
#endif

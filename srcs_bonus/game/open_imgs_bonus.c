/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_imgs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:05:02 by janhan            #+#    #+#             */
/*   Updated: 2024/01/22 10:17:12 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/player_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/player_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/player_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/plant_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/plant_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/effect_w.xpm",
			&game->img_size.x, &game->img_size.y);
}

static void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/enemy_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_02 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/enemy_02.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/enemy_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_02 = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/enemy_04.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
}

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"srcs_bonus/sprites/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_imgs(t_game *game)
{
	open_wallimgs_up (game);
	open_wallimgs_down (game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
	open_door_imgs(game);
}

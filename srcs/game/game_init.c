/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:29:11 by janhan            #+#    #+#             */
/*   Updated: 2024/01/22 09:41:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_tile	**map_init(int ac, char **av, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(ac, av[1]))
		return (NULL);
	map = read_map(av[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

static void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 26;
	game->effect.frames = 7;
	game->enemy_imgs.basic_anim = 16;
	game->enemy_imgs.follow_anim = 6;
	game->player.framecount = 0;
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->window_size.x + IMG_SIZE / 2,
			game->window_size.y, "so_long");
	open_imgs(game);
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
	game->state = TRUE;
}

t_bool	open_checker(t_game *game)
{
	if (!game->door_open_img
		|| !game->door_open_img
		|| !game->collects_imgs.img_0
		|| !game->collects_imgs.img_1
		|| !game->enemy_imgs.basic_01
		|| !game->enemy_imgs.basic_02
		|| !game->enemy_imgs.follow_01
		|| !game->enemy_imgs.follow_02
		|| !game->player.idle_img_0
		|| !game->player.idle_img_1
		|| !game->player.action_img
		|| !game->wall_imgs.block
		|| !game->wall_imgs.up
		|| !game->wall_imgs.up_left
		|| !game->wall_imgs.up_right
		|| !game->wall_imgs.down
		|| !game->wall_imgs.down_left
		|| !game->wall_imgs.down_right
		|| !game->wall_imgs.left
		|| !game->wall_imgs.right)
	{
		null_error("open imgs faile in open_checker()");
		return (FALSE);
	}
	return (1);
}

t_bool	start(t_game *game, int ac, char **av)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(ac, av, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game_init(game);
	if (!is_connected(game) || !open_checker(game))
		return (FALSE);
	game->og_collects = game->collects;
	anim_setup(game);
	return (TRUE);
}

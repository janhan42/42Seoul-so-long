/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:23:44 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 11:27:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reset_enemies(t_enemy *enemy)
{
	if (enemy == NULL)
		return ;
	while (TRUE)
	{
		enemy->tile = enemy->og_tile;
		enemy->dir = 0;
		if (enemy->next == NULL)
			break ;
		enemy = enemy->next;
	}
}

int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->tilemap[y] != NULL)
	{
		x = 0;
		while (game->tilemap[y][x].type != 0)
		{
			game->tilemap[y][x].type = game->tilemap[y][x].og_type;
			if (game->tilemap[y][x].type == PLAYER)
				game->player.tile = &game->tilemap[y][x];
			x++;
		}
		y++;
	}
	reset_enemies(game->enemy_list);
	game->moves = 0;
	game->collects = game->og_collects;
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	return (0);
}

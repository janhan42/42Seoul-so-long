/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:36:24 by janhan            #+#    #+#             */
/*   Updated: 2024/01/22 10:28:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	reset_visited(t_tile **tilemap)
{
	int	y;
	int	x;

	y = 0;
	while (tilemap[y])
	{
		x = 0;
		while (tilemap[y][x].type != 0)
		{
			tilemap[y][x].visited = FALSE;
			x++;
		}
		y++;
	}
}

t_tile	*find_player_tile(t_tile **tilemap)
{
	int	y;
	int	x;

	y = 0;
	while (tilemap[y])
	{
		x = 0;
		while (tilemap[y][x].type != 0)
		{
			if (tilemap[y][x].type == PLAYER)
				return (&tilemap[y][x]);
			x++;
		}
		y++;
	}
	return (NULL);
}

t_bool	flood_fill_collectables(t_tile *tile, int *collectable_count)
{
	if (!tile || tile->type == WALL || tile->visited || tile->type == EXIT)
		return (FALSE);
	if (tile->type == COLLECTABLE)
		(*collectable_count)++;
	tile->visited = TRUE;
	if (flood_fill_collectables(tile->up, collectable_count)
		|| flood_fill_collectables(tile->down, collectable_count)
		|| flood_fill_collectables(tile->left, collectable_count)
		|| flood_fill_collectables(tile->right, collectable_count))
		return (TRUE);
	return (FALSE);
}

t_bool	flood_fill_exit(t_tile *tile, t_tiletype target)
{
	if (!tile || tile->type == WALL || tile->visited)
		return (FALSE);
	if (tile->type == target)
		return (TRUE);
	tile->visited = TRUE;
	if (flood_fill_exit(tile->up, target)
		|| flood_fill_exit(tile->down, target)
		|| flood_fill_exit(tile->left, target)
		|| flood_fill_exit(tile->right, target))
		return (TRUE);
	return (FALSE);
}

t_bool	is_connected(t_game *game)
{
	t_tile	*player;
	int		collectable_count;

	player = find_player_tile(game->tilemap);
	if (player == NULL)
		null_error("find failed error on is_connected(player)");
	collectable_count = 0;
	flood_fill_collectables(player, &collectable_count);
	if (collectable_count != game->collects)
		return (error("failed error on is_connected(collectable)"));
	reset_visited(game->tilemap);
	if (collectable_count == game->collects && flood_fill_exit(player, EXIT))
		return (TRUE);
	else
		return (error("failed error on is_connected(exit)"));
}

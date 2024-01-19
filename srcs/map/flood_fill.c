/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:36:24 by janhan            #+#    #+#             */
/*   Updated: 2024/01/17 16:44:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_tile	*find_player_tile(t_tile **tilemap)
{
	int	y;
	int	x;

	y = 0;
	while (tilemap[y])
	{
		x = 0;
		while (tilemap[y][x] != 0)
		{
			if (tilemap[y][x].type == PLAYER)
				return (&tilemap[y][x]);
			x++;
		}
		y++;
	}
	return (NULL);
}

t_bool	is_conneted(t_tile **tilemap, t_tile *start)
{

}

t_bool	flood_fill(t_tile *tile, t_tiletype target)
{
	if (!tile || tile->type == WALL || tile->visited)
		return (FALSE);
	if (tile->type == target)
		return (TRUE);

	tile->visited = TRUE;

	if (flood_fill(tile->up, target) || flood_fill(tile->down, target) ||
		flood_fill(tile->left, target) || flood_fill(tile->right, target)) {
		return (TRUE);
	}
	return (FALSE);
}

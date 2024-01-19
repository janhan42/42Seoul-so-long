/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:36:24 by janhan            #+#    #+#             */
/*   Updated: 2024/01/19 12:34:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 테스트용
#include <stdio.h>

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

t_bool	flood_fill(t_tile *tile, t_tiletype target)
{
	printf("Visiting Tile: Type = %c, Visited = %d\n", tile ? tile->type : 'N', tile ? tile->visited : -1);
		// 타일이 NULL이거나 벽이거나 이미 방문했으면 탐색 중단
	if (!tile || tile->type == WALL || tile->visited)
		return (FALSE);

	// 목표 타일을 찾으면 TRUE 반환
	if (tile->type == target)
		return (TRUE);

	// 현재 타일을 방문했다고 표시
	tile->visited = TRUE;

	// 인접한 타일을 재귀적으로 탐색
	if (flood_fill(tile->up, target) || flood_fill(tile->down, target) ||
		flood_fill(tile->left, target) || flood_fill(tile->right, target)) {
		return (TRUE);
	}

	// 인접한 타일 중에서 목표 타일을 찾지 못했으면 FALSE 반환
	return (FALSE);
}

t_bool is_connected(t_tile **tilemap) {

	t_tile	*player;

	player = find_player_tile(tilemap);
	if (player == NULL)
		null_error("find failed error on is_connected() must have be one Player tile()");
	// flood_fill 함수를 사용하여 'E' 타입의 타일까지 도달 가능한지 확인합니다.
	if (!flood_fill(player, EXIT))
		return (error("is not connected map on is_connected()"));
	return (TRUE);
}



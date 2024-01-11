/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:58:34 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 11:03:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free(tilemap);
}

static void	free_enemys(t_game *game)
{
	t_enemy *next;

	if (game->enemy_list == NULL)
		return ;
	while (TRUE)
	{
		next = game->enemy_list->next;
		free(game->enemy_list);
		if (next == NULL)
			break ;
		game->enemy_list = next;
	}
}

int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	free_enemys(game);
	game->enemy_list = NULL;
	exit(0);
}

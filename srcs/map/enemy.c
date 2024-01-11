/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:48:13 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 10:53:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_enemy	*new_enemy(t_enemytype type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		return (null_error("malloc error on new_enemy(enemy.c)"));
	enemy->type = type;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->og_tile = enemy->tile;
	enemy->next = NULL;
	return (enemy);
}

static t_enemy *last_enemy(t_enemy *list)
{
	if (!list)
		return (NULL);
	if (list->next)
		list = list->next;
	return (list);
}

void	add_enemy(t_game *game, t_enemytype type, t_tile *tile)
{
	t_enemy *new;

	new = new_enemy(type, tile);
	if (new == NULL)
		return ;
	if (game->enemy_list == NULL)
		game->enemy_list = new;
	else
		last_enemy(game->enemy_list)->next = new;
}

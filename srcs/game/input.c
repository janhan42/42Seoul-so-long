/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:22:35 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 12:31:04 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	effect_anim(t_effect *effect, t_vector pos)
{
	effect->counter = 0;
	effect->pos	= pos;
}

void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == EMPTY || tile->type == FOLLOWER)
	{
		move_to_enemy(game, tile);
		return (FALSE);
	}
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

int	input(int key, t_game *game)
{
	t_bool moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved)
	{
		ft_printf("\033[1A\033[2K");
		ft_printf("Moves -> %d\n", ++game->moves);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:37:37 by janhan            #+#    #+#             */
/*   Updated: 2024/01/22 09:40:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anim(&game->effect, pos);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
	game->state = FALSE;
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
	game->state = FALSE;
}

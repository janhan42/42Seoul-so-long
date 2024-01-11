/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:00:34 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 17:59:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	draw_corner(t_tile tile, t_game game, t_vector pos)
{
	if (tile.position.x == 0
		&& tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up_left, pos.x, pos.y);
	else if (tile.position.x == 0
		&& tile.position.y == game.window_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down_left, pos.x, pos.y);
	else if (tile.position.x == game.window_size.x - IMG_SIZE
		&& tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up_right, pos.x, pos.y);
	else if (tile.position.x == game.window_size.x - IMG_SIZE
		&& tile.position.y == game.window_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down_right, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	draw_sides(t_tile tile, t_game game, t_vector pos)
{
	if (tile.position.x == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.left, pos.x, pos.y);
	else if (tile.position.x == game.window_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.right, pos.x, pos.y);
	else if (tile.position.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.up, pos.x, pos.y);
	else if (tile.position.y == game.window_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.down, pos.x, pos.y);
	else
		return (FALSE);
	return (TRUE);
}

void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	if (draw_corner(tile, game, pos))
		return ;
	else if (draw_sides(tile, game, pos))
		return ;
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}

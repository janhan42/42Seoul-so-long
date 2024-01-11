/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:10:58 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 11:18:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


t_color	new_color(int r, int g, int b, int a)
{
	t_color color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	color_panel(t_panel *panel, t_color color)
{
	int	x;
	int	y;

	panel->pixels = mlx_get_data_addr(panel->pointer, &panel->bpp, &panel->line_size, &panel->endian);
	y = 0;
	while (y < panel->size.y)
	{
		x = 0;
		while (x < panel->size.x)
		{
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
			panel->pixels[(x * 4 + panel->line_size * y) + 1] = color.g;
			panel->pixels[(x * 4 + panel->line_size * y) + 2] = color.r;
			panel->pixels[(x * 4 + panel->line_size * y) + 3] = color.a;
			x += 1;
		}
		y += 1;
	}
}

void	*new_panel(t_game *game, t_color color)
{
	t_panel	panel;

	panel.pointer = mlx_new_image(game->mlx, game->window_size.x,
					 	game->window_size.y);
	panel.size.x = game->window_size.x;
	panel.size.y = game->window_size.y;
	color_panel(&panel, color);
	return (panel.pointer);
}

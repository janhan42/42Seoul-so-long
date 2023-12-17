/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:44:19 by janhan            #+#    #+#             */
/*   Updated: 2023/12/17 16:59:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdint.h>
#include <stdlib.h>

// perror("Error: calloc failed\n");
// exit(EXIT_FAILURE);

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

static int	ft_render_next_frame(t_data *data)
{
	ft_put_background(data);
	ft_create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	//window 사이즈 파싱
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
	{
		perror("Error: calloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&data, &map);
	ft_parse_input(&data, av, ac);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error: mlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
							data.size_y, "so_long");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("Error: mlx_loop failed\n");
	exit(EXIT_FAILURE);

}

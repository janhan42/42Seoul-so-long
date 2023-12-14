/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:44:19 by janhan            #+#    #+#             */
/*   Updated: 2023/12/14 17:34:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdint.h>

void	init_info(t_info *info)
{
	info->img_path.wall = "";
	info->img_path.floor = "";
	info->img_path.player = "";
	info->img_path.item = "";
	info->img_path.exit_door = "";
	
}

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*image;
	int		x;
	int		y;
	t_info	info;

	init_info(&info);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "so_long");
	image = mlx_xpm_file_to_image(mlx, "./image.xpm", &x, &y);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			mlx_put_image_to_window(mlx, window, image, x * j, y * i);
		}
	}
	mlx_loop(mlx);
	return (0);
}

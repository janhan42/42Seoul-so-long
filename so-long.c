/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so-long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:44 by janhan            #+#    #+#             */
/*   Updated: 2023/12/04 19:13:41 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*gcc -I /usr/local/include/ so-long.c -L /usr/local/lib/ -framework OpenGL -framework AppKit ./mlx/libmlx.a */

#include "./mlx/mlx.h"

int main(void)
{
	void *mlx;

	mlx = mlx_init();

	mlx_new_window(mlx, 500, 500, "so-long");

	mlx_loop(mlx);
}

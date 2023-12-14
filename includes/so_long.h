/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:27:00 by janhan            #+#    #+#             */
/*   Updated: 2023/12/14 17:29:34 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct	s_img_path
{
	char	*wall;
	char	*floor;
	char	*player;
	char	*item;
	char	*exit_door;
}	t_img_path;

typedef struct	s_info
{
	int		map_w;
	int		map_h;
	char	**map;
	t_img_path img_path;
}	t_info;


#endif

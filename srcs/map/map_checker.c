/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:12:29 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 10:30:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_file(int ac, char *file)
{
	if (ac == 1)
		return (error("no args"));
	if (ac > 2)
		print_warnig("only the first file would be used");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("map should be a .ber file"));
	return (1);
}

static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.x = 0;
	data.point.y = 0;
	return (data);
}
static int	checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
		return (error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by wall '1'"));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	t_bool				vaild;

	data = init_checkerdata(map);
	vaild = TRUE;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != data.size.x)
			vaild = error("map must be rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				vaild = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		vaild = error("there must be one 'P' and 'E' and least one 'C'");
	return (vaild);
}

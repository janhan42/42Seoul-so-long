/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:09:47 by janhan            #+#    #+#             */
/*   Updated: 2024/01/02 08:47:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("no args"));
	if (argc > 2)
		print_warning("only the first file would be used");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("map should be a .ber file"));
	return (1);
}

static t_mapdata init_checkerdata(char **map)
{
	t_mapdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y	= ft_chartable_linecount(map);
	data.b_collect = FALSE;
	data.b_exit = FALSE;
	data.b_player = FALSE;
	data.point.x = 0;
	data.point.y = 0;
	return (data);
}

static int	checks(char **maps, t_mapdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(maps[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
		return (error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

int	valid_map(char **map)
{
	t_mapdata	data;
	t_bool		valid;

	data = init_checkerdata(map);
	valid = TURE;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != data.size.x)
			valid = error("map must be rectangular");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_collect || !data.b_exit || !data.b_player)
		valid = error("there must be one 'P and 'E', and ay least one 'C'");
	return (valid);
}

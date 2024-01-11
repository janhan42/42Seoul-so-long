/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:19:05 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 10:32:00 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* 유효한 맵 인자인지 체크 */
int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'H' || c == 'V' || c == 'F')
		return (TRUE);
	return (FALSE);
}
/* 인자 중복 체크 */
int	valid_uniquechar(char c, char checker, t_bool *state)
{
	if (c == checker && *state == FALSE)
		*state = TRUE;
	else if (c == checker && *state == TRUE)
		return (FALSE);
	return (TRUE);
}
/* 맵 벽 체크 */
int	valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0
		|| point.y == size.y - 1 || point.x == size.x - 1)
		if (c != '1')
			return (FALSE);
	return (TRUE);
}

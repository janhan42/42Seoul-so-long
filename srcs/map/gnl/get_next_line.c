/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:35:30 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 09:47:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <sys/syslimits.h>

/*
 * 매개변수가 유효 한지 확인 유효하지 않으면 -1 리턴
 * readbuff가 null이였으면 빈 문자열로 설정
 */
int	validparmas(int fd, char **lien, char **readbuff)
{
	if (*readbuff == NULL)
	{
		*readbuff = malloc(sizeof(char));
		if (*readbuff == NULL)
			return (-1);
		**readbuff = '\0';
	}
	if (fd < 0 || !lien
		|| BUFFER_SIZE <= 0 || fd > OPEN_MAX)
	{
		free(*readbuff);
		*readbuff = NULL;
		return (-1);
	}
	return (1);
}

int	ft_end_of_read(int readcount, char **readbuff, char **line)
{
	int	len;

	if (readcount == 0 && ft_strlen(*readbuff) == 0)
	{
		free(*readbuff);
		*readbuff = NULL;
		*line = malloc(sizeof(char));
		**line = '\0';
	}
	else if (readcount == 0)
	{
		len = ft_strlen(*readbuff);
		*line = ft_getline(len, *readbuff);
		free(*readbuff);
		*readbuff = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char *readbuff;
	int			linelen;
	int			readcount;

	if (validparmas(fd, line, &readbuff) < 0)
		return (-1);
	linelen = ft_linelen(readbuff);
	while (linelen < 0)
	{
		readcount = ft_newread(fd, &readbuff);
		if (!readbuff || readcount < 0)
			return (-1);
		else if (readcount == 0)
			return (ft_end_of_read(readcount, &readbuff, line));
		linelen = ft_linelen(readbuff);
	}
	*line = ft_getline(linelen, readbuff);
	readbuff = ft_clearline(linelen + 1, readbuff);
	return (1);
}

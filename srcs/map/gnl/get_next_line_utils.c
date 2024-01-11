/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:49:27 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 10:07:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
 * ft_linelen();
 * 라인의 '\n'(개행) 이 있을때 i를 리턴
 * 없으면 -1을 리턴
*/
int	ft_linelen(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
/*
 * ft_getline();
 * 문자열에서 len만큼 새로운 문자열을 생성해서 리턴
 * 말록 실패시 -1리턴
*/
char	*ft_getline(int len, char *read)
{
	char	*line;
	int		i;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* 저장된 부분인 len을 제외한 뒷부분을 새로 만들어서 리턴 */
char	*ft_clearline(int len, char *read)
{
	char	*result;
	int		i;

	if (read == NULL || (ft_strlen(read) - len + 1) == 0)
		return (NULL);
	result = malloc(ft_strlen(read) - len + 1);
	i = 0;
	while (read[len + 1])
	{
		result[i] = read[len + i];
		i++;
	}
	result[i] = '\0';
	free(read);
	return (result);
}
/*
 * 기존에 있던 oldread의 길이와 새로 읽은 길이 + 1 만큼의
 * 크기를 가지는 result를 새로 만들고 이어준뒤
 * 기존 포인터를 가르키고 있던 걸 프리후 result를 보게 이어줌
*/
int	ft_newread(int fd, char **oldread)
{
	int		count;
	int		i;
	int		new_i;
	char	newread[BUFFER_SIZE + 1];
	char	*result;

	count = read(fd, newread, BUFFER_SIZE);
	newread[count] = '\0';
	result = malloc(ft_strlen(*oldread) + count + 1);
	if (!result)
		return (-1);
	i = 0;
	while (oldread[0][i])
	{
		result[i] = oldread[0][i];
		i++;
	}
	new_i = 0;
	while (newread[new_i])
		result[i++] = newread[new_i++];
	result[i] = '\0';
	free(*oldread);
	*oldread = result;
	return (count);
}

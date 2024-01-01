/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:53:08 by janhan            #+#    #+#             */
/*   Updated: 2024/01/02 08:03:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_getline(int len, char *read)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clearline(int len, char *read)
{
	char	*result;
	int		i;

	if (read == NULL || (ft_strlen(read) - len + 1) == 0)
		return (NULL);
	i = 0;
	result = malloc(ft_strlen(read) - len + 1);
	if (!result)
		return (NULL);
	while (read[len + i])
	{
		result[i] = read[len +i];
		i++;
	}
	result[i] = '\0';
	free (read);
	return (result);
}

int	ft_newread(int fd, char **oldread)
{
	int		count;
	char	new_read[BUFFER_SIZE + 1];
	char	*result;
	int		i;
	int		new_i;

	count = read(fd, new_read, BUFFER_SIZE);
	new_read[count] = '\0';
	result = malloc(ft_strlen(*oldread) + count + 1);
	if (!result || count == -1)
		return (-1);
	i = 0;
	while (oldread[0][i])
	{
		result[i] = oldread[0][i];
		i++;
	}
	new_i = 0;
	while (new_read[new_i])
		result[i++] = new_read[new_i++];
	result[i] = '\0';
	free (*oldread);
	*oldread = result;
	return (count);
}

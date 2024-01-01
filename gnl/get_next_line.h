/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 07:42:52 by janhan            #+#    #+#             */
/*   Updated: 2024/01/02 08:05:59 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* get_next_line_utils */

char	*ft_getline(int len, char *read);
char	*ft_clearline(int len, char *read);
int		ft_newread(int fd, char **oldread);
int		ft_linelen(char *line);

/* get_next_line */

int		validparams(int fd, char **line, char **readbuff);
int		end_of_read(int rdcount, char **readbuff, char **line);
int		get_next_line(int fd, char **line);

#endif

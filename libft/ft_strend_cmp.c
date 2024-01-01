/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:40:07 by janhan            #+#    #+#             */
/*   Updated: 2024/01/02 08:42:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	exit_len;

	name_len = ft_strlen(name);
	exit_len = ft_strlen(end);

	if (name_len <= exit_len)
		return (0);
	name += name_len - exit_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

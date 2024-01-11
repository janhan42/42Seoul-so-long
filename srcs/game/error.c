/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:13:59 by janhan            #+#    #+#             */
/*   Updated: 2024/01/11 13:16:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error(char *message)
{
	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

void	print_warnig(char *message)
{
	ft_printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:45:24 by janhan            #+#    #+#             */
/*   Updated: 2023/12/17 16:45:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_win(t_data *data)
{
	printf("Congratulations, you found all the Diamonds and the exit.\n");
	printf("You won!\n");
	printf("Is %d moves really the best you can do?\n", data->counter);
	exit(EXIT_SUCCESS);
}

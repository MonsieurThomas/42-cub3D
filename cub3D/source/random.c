/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:02:52 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 19:59:24 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

int	ft_print_error(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_destroy_windows(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_putstr_fd("Game over\n", 1);

	exit(1);
	return (1);
}

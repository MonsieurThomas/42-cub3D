/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:02:52 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/21 13:50:28 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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

int	nb_commas(char *str)
{
	int	nb_commas;
	int	i;

	nb_commas = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nb_commas++;
		i++;
	}
	return (nb_commas);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
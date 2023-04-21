/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:02:52 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/21 19:07:29 by romainthoma      ###   ########.fr       */
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

char	*str_remove_charset(char *str, char *set)
{
	int		i;
	int		j;
	char	*new;
	char	*buf;

	i = -1;
	j = -1;
	if (!str)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!buf)
		return (NULL);
	while (str[++i])
	{
		if (!ft_strchr(set, str[i]))
			buf[++j] = str[i];
	}
	buf[++j] = '\0';
	new = ft_strdup(buf);
	free(buf);
	return (new);
}

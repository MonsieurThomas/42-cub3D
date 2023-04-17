/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:44:13 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:52:21 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	tab_to_space_loop(t_data *data, int i, int j, char *str)
{
	if (data->map[i][j] == 9)
	{
		data->j = 0;
		data->k = 0;
		str = malloc(sizeof(char) * 10000);
		data->is_changed += 1;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 9)
			{
				data->f = 0;
				while ((data->f)++ < 4)
					str[(data->k)++] = ' ';
				j++;
			}
			str[(data->k)++] = data->map[i][j++];
		}
		(data->j) = -1;
	}
	if (data->is_changed)
	{
		free(data->map[i]);
		data->map[i] = ft_strdup(str);
		free(str);
	}
}

void	tab_to_space(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = NULL;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			data->is_changed = 0;
			tab_to_space_loop(data, i, j, str);
			j++;
		}
		i++;
	}
}

int	check_around_each_zero(t_data *data, int i, int j)
{
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != '0')
		return (ft_print_error("Error\nProbleme de carte", NULL));
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != '0')
		return (ft_print_error("Error\nProbleme de carte", NULL));
	if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != '0')
		return (ft_print_error("Error\nProbleme de carte", NULL));
	if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != '0')
		return (ft_print_error("Error\nProbleme de carte", NULL));
	return (0);
}

int	check_whole_frontier(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->map[0][++i])
		if (data->map[0][i] == '0')
			return (ft_print_error("Error\nProbleme de carte", NULL));
	i = -1;
	while (data->map[++i])
		if (data->map[i][0] == '0' || \
		data->map[i][ft_strlen(data->map[i]) - 1] == '0')
			return (ft_print_error("Error\nProbleme de carte", NULL));
	i--;
	while (data->map[i][j])
	{
		if (data->map[i][j] == '0')
			return (ft_print_error("Error\nProbleme de carte", NULL));
		j++;
	}
	return (0);
}

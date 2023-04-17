/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:41:56 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:51:47 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	is_any_weird_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' && \
			(data->map[i][j] < 9 || data->map[i][j] > 13) && \
			data->map[i][j] != ' ' && data->map[i][j] != '\n')
				return (ft_print_error("Error\nProbleme de carte", NULL));
			j++;
		}
		i++;
	}
	return (0);
}

int	is_frontier_around_zeros(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_whole_frontier(data))
		return (1);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				if (check_around_each_zero(data, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_problem_with_map(t_data *data)
{
	if (where_is_player(data))
		return (1);
	if (is_any_weird_char(data))
		return (1);
	change_player_pov(data);
	tab_to_space(data);
	if (is_frontier_around_zeros(data))
		return (1);
	return (0);
}

int	create_new_map(t_data *data, int i)
{
	int		j;
	char	**tab;

	data->is_map += 1;
	j = i;
	while (data->map[j])
		j++;
	tab = (char **)malloc(sizeof(char *) * (j) + 1);
	j = 0;
	while (data->map[i])
		tab[j++] = ft_strdup(data->map[i++]);
	tab[j] = 0;
	free_tab(data->map);
	data->map = (char **)malloc(sizeof(char *) * ((j) + 1));
	i = -1;
	while (tab[++i])
		data->map[i] = ft_strdup(tab[i]);
	data->map[i] = 0;
	free_tab(tab);
	if (is_problem_with_map(data))
		return (1);
	return (0);
}

int	is_beginning_of_map(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] == '1')
			return (1);
		j++;
	}
	return (0);
}

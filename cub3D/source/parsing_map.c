/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:12:51 by cleblais          #+#    #+#             */
/*   Updated: 2023/04/21 13:51:29 by cleblais         ###   ########.fr       */
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
				return (ft_print_error("Error\nProbleme de carte9", NULL));//9
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
	}// verif que ya pas de ligne vide 
	return (0);
}

int	is_empty_line(t_data *data)
{
	int	i;
	int	j;
	int	line_empty;

	i = 0;
	j = 0;
	line_empty = 1;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] != ' ')
				line_empty = 0;
			j++;
		}
		if (line_empty)
			return (ft_print_error("Error\nProbleme de carte30", NULL));//30
		line_empty = 1;
		j = 0;
		i++;
	}
	return(0);
}


int	is_problem_with_map(t_data *data)
{
	if (is_empty_line(data))
		return (1);
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

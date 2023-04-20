/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:44:13 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/20 15:37:04 by cleblais         ###   ########.fr       */
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

int	bad_coordinate(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i <= x)
	{
		if (!data->map[i])
			return (1);
		i++;
	}
	i = 0;
	while (i <= y)
	{
		if (!data->map[x][i])
			return (1);
		i++;
	}
	return (0);
}

int	check_around_each_zero(t_data *data, int i, int j)
{
	if (i < 1 || j < 1 || !data->map)
		return (ft_print_error("Error\nProbleme de carte3", NULL));//3
	if (bad_coordinate(data, i - 1, j) || bad_coordinate(data, i, j - 1) \
		|| bad_coordinate(data, i, j + 1) || bad_coordinate(data, i + 1, j))
		return (ft_print_error("Error\nProbleme de carte4", NULL));//4
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != '0')
		return (ft_print_error("Error\nProbleme de carte5", NULL));//5
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != '0')
		return (ft_print_error("Error\nProbleme de carte6", NULL));//6
	if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != '0')
		return (ft_print_error("Error\nProbleme de carte7", NULL));//7
	if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != '0')
		return (ft_print_error("Error\nProbleme de carte8", NULL));//8
	return (0);
}

int	check_whole_frontier(t_data *data) // ATTENTION MAP 167 ok ?
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->map[0][++i])
		if (data->map[0][i] == '0')
			return (ft_print_error("Error\nProbleme de carte9", NULL));//9
	i = -1;
	while (data->map[++i])
		if (data->map[i][0] == '0' || \
		data->map[i][ft_strlen(data->map[i]) - 1] == '0')
			return (ft_print_error("Error\nProbleme de carte10", NULL));//10
	i--;
	while (data->map[i][j])
	{
		if (data->map[i][j] == '0')
			return (ft_print_error("Error\nProbleme de carte11", NULL));//11
		j++;
	}
	return (0);
}

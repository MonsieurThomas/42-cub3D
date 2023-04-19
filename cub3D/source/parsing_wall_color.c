/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wall_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:00:48 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/19 16:49:08 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	put_wall_in_struct(t_data *data, int i)
{
	char	**str;

	data->wall++;
	str = ms_split(data->map[i], ' ');
	if (!str || !str[0] || !str[1] || str[2])
		return (ft_print_error("Error\nProbleme de textures", NULL));
	if (!ft_strncmp(data->map[i], "NO ", 3))
		data->no = ft_strdup(str[1]);
	if (!ft_strncmp(data->map[i], "SO ", 3))
		data->so = ft_strdup(str[1]);
	if (!ft_strncmp(data->map[i], "WE ", 3))
		data->we = ft_strdup(str[1]);
	if (!ft_strncmp(data->map[i], "EA ", 3))
		data->ea = ft_strdup(str[1]);
	free_tab(str);
	return (0);
}

int	is_color_legit(t_data *data, char letter)
{
	if (letter == 'F')
	{
		if (data->f1 < 0 || data->f2 < 0 || data->f3 < 0 || \
		data->f1 > 255 || data->f2 > 255 || data->f3 > 255)
			return (ft_print_error("Error\nProbleme de couleurs", NULL));
		else
			data->floor_color = (data->f1 << 16) | (data->f2 << 8) | (data->f3);
	}
	if (letter == 'C')
	{
		if (data->c1 < 0 || data->c2 < 0 || data->c3 < 0 || \
		data->c1 > 255 || data->c2 > 255 || data->c3 > 255)
			return (ft_print_error("Error\nProbleme de couleurs2", NULL));
		else
			data->ceil_color = (data->c1 << 16) | (data->c2 << 8) | (data->c3);
	}
	return (0);
}

int	color_to_struct(t_data *data, char **tab, char letter)
{
	if (letter == 'F')
	{
		data->color_f += 1;
		data->f1 = ft_atoi(tab[0]);
		data->f2 = ft_atoi(tab[1]);
		data->f3 = ft_atoi(tab[2]);
		if (is_color_legit(data, 'F'))
			return (1);
	}
	if (letter == 'C')
	{
		data->color_c += 1;
		data->c1 = ft_atoi(tab[0]);
		data->c2 = ft_atoi(tab[1]);
		data->c3 = ft_atoi(tab[2]);
		if (is_color_legit(data, 'C'))
			return (1);
	}
	return (0);
}

void	printf_strs(char **strs) //*************
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
		{
			printf("%d] %s\n", i, strs[i]);
			i++;
		}
	}
}



int	get_color(t_data *data, int i)
{
	char	**str;
	char	**tab;

	str = ms_split(data->map[i], ' ');
	tab = ms_split(str[1], ',');
	if (!str || !str[0] || !str[1] || !tab || !tab[0]|| !tab[1] || !tab[2])
		return (ft_print_error("Error\nProbleme de couleurs", NULL));
	if (tab[3] || str[2])
	{
		free_tab(str);
		free_tab(tab);
		return (ft_print_error("Error\nProbleme de couleurs", NULL));
	}
	if (!ft_strncmp(data->map[i], "F ", 2))
	{
		if (color_to_struct(data, tab, 'F'))
			return (1);
	}
	else
	{
		if (color_to_struct(data, tab, 'C'))
			return (1);
	}
	free_tab(str);
	free_tab(tab);
	return (0);
}

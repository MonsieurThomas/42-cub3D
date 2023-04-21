/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wall_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:13:12 by cleblais          #+#    #+#             */
/*   Updated: 2023/04/21 17:18:59 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	put_wall_in_struct(t_data *data, int i)
{
	char	**str;

	data->wall++;
	str = secure_split(data->map[i], ' ');
	if (!str || !str[0] || !str[1] || str[2])
	{
		if (str)
			free_tab(str);
		return (ft_print_error("Error\nTexture problem21", NULL));//21
	}
	if (!ft_strncmp(data->map[i], "NO ", 3) && !data->no)
		data->no = ft_strdup(str[1]);
	if (!ft_strncmp(data->map[i], "SO ", 3) && !data->so)
		data->so = ft_strdup(str[1]);
	if (!ft_strncmp(data->map[i], "WE ", 3) && !data->we)
		data->we = ft_strdup(str[1]);
	if (!ft_strncmp(data->map[i], "EA ", 3) && !data->ea)
		data->ea = ft_strdup(str[1]);
	free_tab(str);
	return (0);
}

int	is_color_legit(t_data *data, char letter)
{
	if (letter == 'F')
	{
		if (data->color_f != 1 || data->f1 < 0 || data->f2 < 0 || \
		data->f3 < 0 || data->f1 > 255 || data->f2 > 255 || data->f3 > 255)
			return (ft_print_error("Error\nColor problem22", NULL));//22
		else
			data->floor_color = (data->f1 << 16) | (data->f2 << 8) | (data->f3);
	}
	if (letter == 'C')
	{
		if (data->color_c != 1 || data->c1 < 0 || data->c2 < 0 || \
			data->c3 < 0 || data->c1 > 255 || data->c2 > 255 || data->c3 > 255)
			return (ft_print_error("Error\nColor problem23", NULL));//23
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
		data->f1 = cub_atoi(tab[0]);
		data->f2 = cub_atoi(tab[1]);
		data->f3 = cub_atoi(tab[2]);
		if (is_color_legit(data, 'F'))
			return (1);
	}
	if (letter == 'C')
	{
		data->color_c += 1;
		data->c1 = cub_atoi(tab[0]);
		data->c2 = cub_atoi(tab[1]);
		data->c3 = cub_atoi(tab[2]);
		if (is_color_legit(data, 'C'))
			return (1);
	}
	return (0);
}

int	set_color_to_struct(t_data *data, int i, char ***tab)
{
	if (!ft_strncmp(data->map[i], "F ", 2))
	{
		if (color_to_struct(data, *tab, 'F'))
		{
			free_tab(*tab);
			return (1);
		}
	}
	else
	{
		if (color_to_struct(data, *tab, 'C'))
		{
			free_tab(*tab);
			return (1);
		}
	}
	return (0);
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

int	get_color(t_data *data, int i)
{
	char	*str;
	char	**tab;

	if (nb_commas(data->map[i]) != 2)
		return (ft_print_error("Error\nColor problem40", NULL));//40
	str = str_remove_charset(data->map[i], " CF");
	if (!str)
		return (ft_print_error("Error\nColor problem41", NULL));//41
	tab = secure_split(str, ',');
	free(str);
	if (!tab || !tab[0] || !tab[1] || !tab[2] || tab[3])
	{
		if (tab)
			free_tab(tab);
		return (ft_print_error("Error\nColor problem26", NULL));//26
	}
	if (set_color_to_struct(data, i, &tab))
		return (1);
	free_tab(tab);
	return (0);
}

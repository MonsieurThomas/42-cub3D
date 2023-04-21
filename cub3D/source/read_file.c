/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:03:25 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/21 16:36:52 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	get_nb_line(t_data *data)
{
	int		fd;
	int		nb_line;
	char	*line;

	fd = open(data->av, O_RDONLY);
	nb_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		nb_line++;
	}
	free(line);
	close(fd);
	return (nb_line);
}

int	read_map(t_data *data)
{
	int		fd;
	int		nb_line;
	char	*line;

	nb_line = get_nb_line(data);
	fd = open(data->av, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	data->map[nb_line] = NULL;
	data->i = 0;
	while (data->i < nb_line)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > 101)
		{
			free(line);
			return(ft_print_error("Error\nMap too big for MinilibX", NULL));
		}
		data->map[data->i] = ft_strdup(line);
		if (data->map[data->i][ft_strlen(line) - 1] == '\n')
			data->map[data->i][ft_strlen(line) - 1] = 0;
		free(line);
		data->i++;
	}
	if (data->i < 3)
	{
		ft_putstr_fd("Error\nMap problem28\n", 1);//28
		return (1);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:18:35 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:50:57 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	change_player(t_data *data)
{
	data->player_pov = data->map[data->i][data->j];
	data->map[data->i][data->j] = '0';
	data->player_y = data->j;
	data->player_x = data->i;
	(data->player_nb)++;
}

int	where_is_player(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->player_nb = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'N' || \
			data->map[data->i][data->j] == 'S' || \
			data->map[data->i][data->j] == 'E' || \
			data->map[data->i][data->j] == 'W')
				change_player(data);
			(data->j)++;
		}
		(data->i)++;
	}
	if (data->player_nb != 1)
		return (ft_print_error("Error\nProbleme de joueur", NULL));
	return (0);
}

void	change_player_pov(t_data *data)
{
	if (data->player_pov == 'S')
	{
		data->main_dir_x = 1;
		data->fov_y = -0.66;
	}
	if (data->player_pov == 'W')
	{
		data->main_dir_y = -1;
		data->main_dir_x = 0;
		data->fov_x = -0.66;
		data->fov_y = 0;
	}
	if (data->player_pov == 'E')
	{
		data->main_dir_y = 1;
		data->fov_x = 0.66;
		data->fov_y = 0;
		data->main_dir_x = 0;
	}
}

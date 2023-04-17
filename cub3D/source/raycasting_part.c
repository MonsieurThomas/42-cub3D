/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 22:33:21 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:50:09 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	choose_texture(t_data *data)
{
	if (data->is_frontal == 0 && data->ray_x < 0)
		data->texture_num = 0;
	if (data->is_frontal == 0 && data->ray_x >= 0)
		data->texture_num = 1;
	if (data->is_frontal == 1 && data->ray_y < 0)
		data->texture_num = 2;
	if (data->is_frontal == 1 && data->ray_y >= 0)
		data->texture_num = 3;
}

void	getting_predeltas(t_data *data)
{
	if (data->ray_x < 0)
	{
		data->wich_side_x = -1;
		data->predelta_x = (data->player_x - data->map_x) * data->delta_x;
	}
	else
	{
		data->wich_side_x = 1;
		data->predelta_x = (data->map_x + 1.0 - data->player_x) * data->delta_x;
	}
	if (data->ray_y < 0)
	{
		data->wich_side_y = -1;
		data->predelta_y = (data->player_y - data->map_y) * data->delta_y;
	}
	else
	{
		data->wich_side_y = 1;
		data->predelta_y = (data->map_y + 1.0 - data->player_y) * data->delta_y;
	}
}

void	getting_deltas(t_data *data)
{
	data->delta_y = sqrt(1 + (data->ray_x * data->ray_x) \
	/ (data->ray_y * data->ray_y));
	data->delta_x = sqrt(1 + (data->ray_y * data->ray_y) \
	/ (data->ray_x * data->ray_x));
}

void	is_hit(t_data *data)
{
	if (data->predelta_x < data->predelta_y)
	{
		data->predelta_x += data->delta_x;
		data->map_x += data->wich_side_x;
		data->is_frontal = 0;
	}
	else
	{
		data->predelta_y += data->delta_y;
		data->map_y += data->wich_side_y;
		data->is_frontal = 1;
	}
	if (data->map[data->map_x][data->map_y] == '1')
		data->hit = 1;
}

void	raycasting(t_data *data)
{
	data->x = 0;
	while (data->x < data->img_width)
	{
		data->camera_plane = 2 * data->x / (double) data->img_width - 1;
		data->ray_x = data->main_dir_x + data->fov_x * data->camera_plane;
		data->ray_y = data->main_dir_y + data->fov_y * data->camera_plane;
		data->map_x = (int) data->player_x;
		data->map_y = (int) data->player_y;
		getting_deltas(data);
		getting_predeltas(data);
		data->hit = 0;
		while (data->hit == 0)
			is_hit(data);
		perpwall_and_drawing(data);
		(data->x)++;
	}
}

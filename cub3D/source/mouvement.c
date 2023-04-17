/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:12:25 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:57:53 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	rot_left(t_data *data)
{
	double	temp;

	temp = data->main_dir_x;
	data->main_dir_x = data->main_dir_x * cos(data->rotspeed / 2) - \
	data->main_dir_y * sin(data->rotspeed / 2);
	data->main_dir_y = temp * sin(data->rotspeed / 2) + \
	data->main_dir_y * cos(data->rotspeed / 2);
	temp = data->fov_x;
	data->fov_x = data->fov_x * cos(data->rotspeed / 2) - \
	data->fov_y * sin(data->rotspeed / 2);
	data->fov_y = temp * sin(data->rotspeed / 2) + \
	data->fov_y * cos(data->rotspeed / 2);
}

void	rot_right(t_data *data)
{
	double	temp;

	temp = data->main_dir_x;
	data->main_dir_x = data->main_dir_x * cos(-data->rotspeed / 2) - \
	data->main_dir_y * sin(-data->rotspeed / 2);
	data->main_dir_y = temp * sin(-data->rotspeed / 2) + \
	data->main_dir_y * cos(-data->rotspeed / 2);
	temp = data->fov_x;
	data->fov_x = data->fov_x * cos(-data->rotspeed / 2) \
	- data->fov_y * sin(-data->rotspeed / 2);
	data->fov_y = temp * sin(-data->rotspeed / 2) + \
	data->fov_y * cos(-data->rotspeed / 2);
}

void	forward_backward(t_data *data)
{
	if (data->forward)
	{
		if (data->map[(int)(floor(data->player_x + data->main_dir_x * \
		data->move_speed))][(int)floor(data->player_y)] == '0')
			data->player_x += data->main_dir_x * data->move_speed;
		if (data->map[(int)floor((data->player_x))][(int)floor(\
		(data->player_y + data->main_dir_y * data->move_speed))] == '0')
			data->player_y += data->main_dir_y * data->move_speed;
	}
	if (data->backward)
	{
		if (data->map[(int)(floor(data->player_x - data->main_dir_x * \
		data->move_speed))][(int)floor(data->player_y)] == '0')
			data->player_x -= data->main_dir_x * data->move_speed;
		if (data->map[(int)floor((data->player_x))][(int)floor((data->player_y \
		- data->main_dir_y * data->move_speed))] == '0')
			data->player_y -= data->main_dir_y * data->move_speed;
	}
}

void	leftward_backward(t_data *data)
{
	if (data->leftward)
	{
		if (data->map[(int)(floor((data->player_x - data->main_dir_y * \
		data->move_speed)))][(int)(floor(data->player_y))] == '0')
			data->player_x -= data->main_dir_y * data->move_speed / 1.5;
		if (data->map[(int)(floor(data->player_x))][(int)(floor(\
		(data->player_y + data->main_dir_x * data->move_speed)))] == '0')
			data->player_y += data->main_dir_x * data->move_speed / 1.5;
	}
	if (data->rightward)
	{
		if (data->map[(int)floor((data->player_x + data->main_dir_y * \
		data->move_speed))][(int)floor(data->player_y)] == '0')
			data->player_x += data->main_dir_y * data->move_speed / 1.5;
		if (data->map[(int)(floor(data->player_x))][(int)floor(\
		(data->player_y - data->main_dir_x * data->move_speed))] == '0')
			data->player_y -= data->main_dir_x * data->move_speed / 1.5;
	}
}

int	mouvement(t_data *data)
{
	if (data->forward || data->backward)
		forward_backward(data);
	if (data->leftward || data->rightward)
		leftward_backward(data);
	if (data->rot_left)
		rot_left(data);
	if (data->rot_right)
		rot_right(data);
	return (0);
}

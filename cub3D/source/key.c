/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:07:44 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:25:41 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == 49)
		data->move_speed = 0.1;
	if (keycode == 53)
		data->kill_win = 1;
	if (keycode == 13 || keycode == 17)
		data->forward = 1;
	if (keycode == 1)
		data->backward = 1;
	if (keycode == 2)
		data->rightward = 1;
	if (keycode == 0)
		data->leftward = 1;
	if (keycode == 123)
		data->rot_left = 1;
	if (keycode == 124)
		data->rot_right = 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == 49)
		data->move_speed = 0.05;
	if (keycode == 53)
		data->kill_win = 0;
	if (keycode == 13)
		data->forward = 0;
	if (keycode == 1)
		data->backward = 0;
	if (keycode == 2)
		data->rightward = 0;
	if (keycode == 0)
		data->leftward = 0;
	if (keycode == 123)
		data->rot_left = 0;
	if (keycode == 124)
		data->rot_right = 0;
	if (keycode == 53 || keycode == 8)
		ft_destroy_windows(data);
	return (0);
}

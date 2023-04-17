/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:55:45 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:56:24 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	show_minimap_loop(t_data *d, int i, int x, int y)
{
	while ((d->deb_x + x) < 549 && d->map[x / d->div_x])
	{
		y = 0;
		while ((d->deb_y + y) < 549)
		{
			if ((ft_strlen(d->map[x / d->div_x]) - 1 >= (y / d->div_y)) \
			&& (i - 1 >= (x / d->div_x)))
			{
				if ((d->map[x / d->div_x][y / d->div_y]) == '1')
					my_mlx_pixel_put(d, (d->deb_y + y), (d->deb_x + x), \
					0xFF0000);
				else if ((d->map[x / d->div_x][y / d->div_y]) == '0')
					my_mlx_pixel_put(d, (d->deb_y + y), (d->deb_x + x), 0);
				if (y / d->div_y == (int)d->player_y && x / d->div_x == \
				(int)d->player_x)
					my_mlx_pixel_put(d, (d->deb_y + y), (d->deb_x + x), \
					0x0000FF);
			}
			y++;
		}
		x++;
	}
}

void	show_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->i = 0;
	data->j = 0;
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
			data->j++;
		if (data->j > data->jmax)
			data->jmax = data->j;
		data->i++;
	}
	data->j = data->jmax;
	data->div_x = 100 / data->i;
	data->div_y = 100 / data->j;
	show_minimap_loop(data, data->i, x, y);
}

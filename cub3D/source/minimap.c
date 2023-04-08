/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:55:45 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 17:59:42 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

void	show_minimap_loop(t_data *d, int i, int x, int y)
{
	while ((d->debX + x) < 549 && d->map[x / d->divX])
	{
		y = 0;
		while ((d->debY + y) < 549)
		{
			if ((ft_strlen(d->map[x / d->divX]) - 1 >= (y / d->divY)) \
			&& (i - 1 >= (x / d->divX)))
			{
				if ((d->map[x / d->divX][y / d->divY]) == '1')
					my_mlx_pixel_put(d, (d->debY + y), (d->debX + x), 0xFF0000);
				else if ((d->map[x / d->divX][y / d->divY]) == '0')
					my_mlx_pixel_put(d, (d->debY + y), (d->debX + x), 0);
				if (y / d->divY == (int)d->posY && x / d->divX == (int)d->posX)
					my_mlx_pixel_put(d, (d->debY + y), (d->debX + x), 0x0000FF);
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
	data->divX = 100 / data->i;
	data->divY = 100 / data->j;
	show_minimap_loop(data, data->i, x, y);
}

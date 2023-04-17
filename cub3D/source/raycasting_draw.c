/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:56:58 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/17 22:54:34 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	draw_wall(t_data *data)
{
	int	color;

	if (data->is_frontal == 0)
		data->texture_x = data->player_y + data->perp_wall * data->ray_y;
	else
		data->texture_x = data->player_x + data->perp_wall * data->ray_x;
	data->texture_x -= floor(data->texture_x);
	data->pixel_x = (int)(data->texture_x * 64);
	data->draw_step = (double)64 / data->line_height;
	data->actual_step = (data->draw_start + data->line_height / 2 - \
	data->img_height / 2) * data->draw_step;
	while (data->draw_start <= data->draw_end)
	{
		data->pixel_y = (int)data->actual_step % 64;
		data->actual_step += data->draw_step;
		color = get_color_texture(data, data->pixel_x, data->pixel_y, \
		data->texture_num);
		my_mlx_pixel_put(data, data->x, data->draw_start, color);
		data->draw_start++;
	}
}

void	perpwall_and_drawing(t_data *data)
{
	if (data->is_frontal == 0)
		data->perp_wall = ((double)data->map_x - \
		data->player_x + (1 - (double)data->wich_side_x) / 2) / data->ray_x;
	else
		data->perp_wall = ((double)data->map_y - \
		data->player_y + (1 - (double)data->wich_side_y) / 2) / data->ray_y;
	choose_texture(data);
	data->line_height = ((double)data->img_height \
	* data->ratio / data->perp_wall);
	data->draw_start = -data->line_height / 2 + data->img_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->img_height / 2;
	if (data->draw_end >= data->img_height)
		data->draw_end = data->img_height - 1;
	data->i = 0;
	while ((data->i)++ < data->draw_start)
		my_mlx_pixel_put(data, data->x, data->i, data->ceil_color);
	draw_wall(data);
	data->i = data->img_height - 1;
	if (data->draw_end > 0)
		while ((data->i)-- > data->draw_end)
			my_mlx_pixel_put(data, data->x, data->i, data->floor_color);
}

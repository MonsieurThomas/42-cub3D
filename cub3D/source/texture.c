/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:53 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 18:06:23 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

void	get_textu_addr(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].addr = mlx_get_data_addr(data->texture[i].img, \
		&data->texture[i].bits_per_pixel, &data->texture[i].line_length, \
		&data->texture[i].endian);
		i++;
	}
}

unsigned int	get_color_textu(t_data *data, int x, int y, int nb)
{
	char	*dst;

	dst = data->texture[nb].addr + (y * data->texture[nb].line_length \
	+ x * (data->texture[nb].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
